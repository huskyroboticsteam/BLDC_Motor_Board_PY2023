#include "main.h"
#include "MotorBoardCAN.h"
#include "MotorBoardFSM.h"
#include "MotorDrive.h"
#include "PID.h"
#include "../HindsightCAN/CANMotorUnit.h"

#ifdef RGB_LED_ARRAY
#include "LED_Array.h"
extern const uint32 StripLights_CLUT[ ];
extern uint8_t address;
#endif

extern int16_t nextPWM;
extern int32_t millidegreeTarget;

extern uint8_t bound_set1;
extern uint8_t bound_set2;
extern int32_t enc_lim_1;
extern int32_t enc_lim_2;

void SendEncoderData (CANPacket *packetToSend){
    //PrintCanPacket(*packetToSend);
    AssembleTelemetryReportPacket(packetToSend, DEVICE_GROUP_JETSON, DEVICE_SERIAL_JETSON, 
        PACKET_TELEMETRY_ANG_POSITION, CurrentPositionMiliDegree());
    SendCANPacket(packetToSend);
}

//Reads from CAN FIFO and changes the state and mode accordingly
void NextStateFromCAN(CANPacket *receivedPacket, CANPacket *packetToSend) {
    uint16_t packageID = ReadCAN(receivedPacket);
    switch(packageID) {
        case(ID_MOTOR_UNIT_MODE_SEL):
            if(GetModeFromPacket(receivedPacket) == MOTOR_UNIT_MODE_PWM) {
                set_PWM(0, 0, 0);
                #ifdef RGB_LED_ARRAY
                StripLights_MemClear(StripLights_BLACK);
                StripLights_Pixel(0, 0, get_color_packet(0,0,255));
                StripLights_Trigger(1);
                #endif
                SetModeTo(MOTOR_UNIT_MODE_PWM);
                SetStateTo(CHECK_CAN);
            }
            else if (GetModeFromPacket(receivedPacket) == MOTOR_UNIT_MODE_PID) {
                InitializePID();
                #ifdef RGB_LED_ARRAY
                StripLights_MemClear(StripLights_BLACK);
                StripLights_Pixel(1, 0, get_color_packet(0,0,255));
                StripLights_Trigger(1);
                #endif
                SetModeTo(MOTOR_UNIT_MODE_PID);
                SetStateTo(CHECK_CAN);
            } else {
                GotoUninitState();
            }
            break;
            
        case(ID_MOTOR_UNIT_PWM_DIR_SET):
            if(GetMode() == MOTOR_UNIT_MODE_PWM){
                SetStateTo(SET_PWM);
                nextPWM = GetPWMFromPacket(receivedPacket);
            } else {
                SetStateTo(QUEUE_ERROR);
                DisplayErrorCode(MOTOR_ERROR_WRONG_MODE);
            }
            break;
            
        case(ID_MOTOR_UNIT_PID_P_SET):
            SetkPosition(GetPFromPacket(receivedPacket));
            PositionConstIsSet();
            SetStateTo(CHECK_CAN);
            break;
        
        case(ID_MOTOR_UNIT_PID_I_SET):
            SetkIntegral(GetIFromPacket(receivedPacket));
            IntegralConstIsSet();
            SetStateTo(CHECK_CAN);
            break;
        
        case(ID_MOTOR_UNIT_PID_D_SET):
            SetkDerivative(GetDFromPacket(receivedPacket));
            DerivativeConstIsSet();
            SetStateTo(CHECK_CAN);
            break;
        
        case(ID_MOTOR_UNIT_PID_POS_TGT_SET):
            if(GetMode() == MOTOR_UNIT_MODE_PID && PIDconstsSet()) {//&& PID values set
                EnablePID();
                millidegreeTarget = GetPIDTargetFromPacket(receivedPacket);
                SetStateTo(CALC_PID);
            } else {
                SetStateTo(QUEUE_ERROR);
                DisplayErrorCode(MOTOR_ERROR_WRONG_MODE);
            }
            break;
         
        case(ID_MOTOR_UNIT_ENC_PPJR_SET):
            SetkPPJR(GetEncoderPPJRFromPacket(receivedPacket));
            PPJRConstIsSet();
            SetStateTo(CHECK_CAN);
            break;
        /*
        case(ID_MOTOR_UNIT_MAX_JNT_REV_SET):
            break;
        */
        case(ID_MOTOR_UNIT_ENC_INIT):
            if(GetMode() == MOTOR_UNIT_MODE_PID){ //turn off and clear PID Loop if encoder is reinit while running
                set_PWM(0, 0, 0);
                ClearPIDProgress();
                DisablePID();
            }
            if(GetEncoderZeroFromPacket(receivedPacket)) {
                QuadDec_SetCounter(0);                        
            }
            if(GetEncoderDirectionFromPacket(receivedPacket)) {
                SetEncoderDirReverse();
            } else {
                SetEncoderDirDefault();
            }
            SetStateTo(CHECK_CAN);
            break;
        case(ID_MOTOR_UNIT_MAX_PID_PWM):
            SetMaxPIDPWM(GetMaxPIDPWMFromPacket(receivedPacket));
            SetStateTo(CHECK_CAN);
            break;
            
        case(ID_MOTOR_UNIT_SET_ENCODER_BOUND):
            if (GetLimSwNumFromPacket(receivedPacket)) { // Limit 2
                bound_set2 = 1;
                enc_lim_2 = GetEncoderValueFromPacket(receivedPacket);
            } else { // Limit 1
                bound_set1 = 1;
                enc_lim_1 = GetEncoderValueFromPacket(receivedPacket);
            }
            
            SetStateTo(CHECK_CAN);
            break;
        
        // Common Packets 
        case(ID_ESTOP):
            set_PWM(0, 0, 0);
            GotoUninitState();
            #ifdef RGB_LED_ARRAY
            StripLights_MemClear(StripLights_BLACK);
            StripLights_Pixel(0, 0, get_color_packet(0,0,255));
            StripLights_Trigger(1);
            #endif
            break;
        
        case(ID_TELEMETRY_PULL):
            //AssembleChipTypeReportPacket(packetToSend, GetSenderDeviceGroupCode(receivedPacket),
            //    GetSenderDeviceSerialNumber(receivedPacket));
            //SendCANPacket(packetToSend);
            SendEncoderData(packetToSend);
            break;

            
            /*
        case(ID_LED_COLOR):
            break;
            */
            
            
        default://for 0xFF/no packets or Non recognized Packets
            
            if(GetMode() == MOTOR_UNIT_MODE_PID) { //need to check if values set;
                SetStateTo(CALC_PID);
            } else if(GetMode() == MOTOR_UNIT_MODE_PWM) { //skips PWM state to not reset saftey timer
                SetStateTo(CHECK_CAN);
            } else {
                SetStateTo(CHECK_CAN);
            }
            
            //recieved Packet with Non Valid ID
            if (packageID != NO_NEW_CAN_PACKET && packageID != 0xF6) {
        
                DisplayErrorCode(MOTOR_ERROR_INVALID_PACKET);
            }
            break;
    }
}