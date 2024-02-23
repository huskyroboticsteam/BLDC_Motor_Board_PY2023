/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "main.h"
#include "BLDC_Debug.h"
#include "cyapicallbacks.h"
#include "BLDC_Drive.h"
#include "BLDC_CAN.h"
#include "BLDC_FSM.h"
#include <math.h>



//LED
uint8_t Can_LED = 0;
uint8_t Debug_LED = 0;
uint8_t Error_LED = 0;

int32_t millidegreeTarget = 0;

//Uart variables
char txData[TX_DATA_SIZE];

//drive varaible
int16 nextPWM = 0;
extern uint8 invalidate;
uint8_t ignoreLimSw = 0;
uint8_t encoderTimeOut = 0;
uint8_t hallSensorsTimeOut = 0;

// Motor Unit Variables
uint8_t bound_set1;
uint8_t bound_set2;
int32_t enc_lim_1;
int32_t enc_lim_2;

//Status and Data Structs
volatile uint8_t drive = 0;
uint8_t CAN_check_delay = 0;
CANPacket can_recieve;
CANPacket can_send;

uint8_t address = 0;

CY_ISR(Period_Reset_Handler) {
    invalidate++;
    Can_LED++;
    CAN_check_delay ++;
    Error_LED++;
    Debug_LED++; // do I need this?

    if(invalidate >= 20){
        set_speed(0, 1);   
    }
    if(Error_LED >= 3) {
        #ifdef ERROR_LED
        ERROR_LED_Write(LED_OFF);
        #endif
        #ifdef DEBUG_LED1   
        Debug_1_Write(LED_OFF);
        #endif
    }
    if(Can_LED >= 3){
        #ifdef CAN_LED
        CAN_LED_Write(LED_OFF);
        #endif
    }
}
  
CY_ISR(Pin_Limit_Handler){
    #ifdef PRINT_LIMIT_SW_TRIGGER
    sprintf(txData,"LimitSW triggerd Stat: %x \r\n", Status_Reg_Switches_Read() & 0b11);
    UART_UartPutString(txData);
    #endif
    
    UART_UartPutString("LIMIT HIT\n\r");
    
    set_speed(GetCurrentSpeed(), ignoreLimSw);
    
    #ifdef CAN_TELEM_SEND
    AssembleLimitSwitchAlertPacket(&can_send, DEVICE_GROUP_JETSON, 
        DEVICE_SERIAL_JETSON, Status_Reg_Switches_Read() & 0b11);
    SendCANPacket(&can_send);
    #endif

    if (bound_set1 && Pin_Limit_1_Read()) {
        setEncoderAtLimit(enc_lim_1);
        UART_UartPutString("Change limit 1\n\r");
    }
    if (bound_set2 && Pin_Limit_2_Read()){
        setEncoderAtLimit(enc_lim_2);
        UART_UartPutString("Change limit 2\n\r");
    }
}


    

int main(void)
{ 
    Initialize();
    
    for(;;)
    {
        switch(GetState()) {
            case(UNINIT):
                //idle animation
                SetStateTo(CHECK_CAN);
                break;
            case(SET_PWM):
                set_speed(nextPWM, ignoreLimSw);
                SetStateTo(CHECK_CAN);
                break;
            case(CALC_PID):
                SetPosition(millidegreeTarget);   
                SetStateTo(CHECK_CAN);
                break;
            case(QUEUE_ERROR):
                SetStateTo(CHECK_CAN);
                break;
            case(CHECK_CAN):
                NextStateFromCAN(&can_recieve, &can_send);
                #ifdef PRINT_CAN_PACKET
                PrintCanPacket(can_recieve);
                #endif
                break;
            default:
                //Should Never Get Here
                //TODO: ERROR
                GotoUninitState();
                break;
        }
        
        if (UART_SpiUartGetRxBufferSize()) {
            DebugPrint(UART_UartGetByte());
        }
    }
}




void Initialize(void) {
    CyGlobalIntEnable; /* Enable global interrupts. LED arrays need this first */
    
    Limit_Register_InterruptEnable();
    
    address = Address_Register_Read();
    
    #ifdef ENABLE_DEBUG_UART
    UART_Start();
    sprintf(txData, "Dip Addr: %x \r\n", address);
    UART_UartPutString(txData);
    #endif
    
    #ifdef ERROR_LED
    ERROR_LED_Write(~(address >> 3 & 1));
    #endif
    #ifdef DEBUG_LED1
    Debug_1_Write(~(address >> 1) & 1);
    #endif 
    #ifdef CAN_LED
    CAN_LED_Write(~address & 1);
    #endif
    
    // Initialize protocols
    InitCAN(0x4, (int)address);
    TMC6100_SPI_Start();
    Current_Sensor_I2C_Start();
    UART_Start();
    Timer_Rotor_Delay_Start();   
    Timer_Period_Reset_Start();   
    
    isr_Limit_1_StartEx(Pin_Limit_Handler);
    isr_Period_Reset_StartEx(Period_Reset_Handler);
}

void DebugPrint(char input) {
    switch(input) {
        case 's':
            // set motor speed to 0.5 rpm
        case 'e':
            sprintf(txData, "Encoder Value: %li  \r\n", QuadDec_GetCounter());
            break;
        case 'f':
            sprintf(txData, "Mode: %x State:%x \r\n", GetMode(), GetState());
            break;
        case 'd':
            sprintf(txData, "P: %i I: %i D: %i Conv: %i Ready: %i \r\n", 
            GetkPosition(), GetkIntegral(), GetkDerivative(), (int) GetConversion(), PIDconstsSet());
            break;
        case 'p':
            sprintf(txData, "Position (mDeg): %i \r\n", GetPositionmDeg());
            break;
        case 'x':
            sprintf(txData, "Value: %d  ADC range: %d-%d  mDeg range: %d-%d  usePot=%d\r\n", 
                            GetPotVal(), GetTickMin(), GetTickMax(),
                            GetmDegMin(), GetmDegMax(), GetUsingPot());
            break;
        default:
            sprintf(txData, "what\r\n");
            break;
    }
    UART_UartPutString(txData);
}

void PrintCanPacket(CANPacket receivedPacket){
    for(int i = 0; i < receivedPacket.dlc; i++ ) {
        sprintf(txData,"Byte%d %x   ", i+1, receivedPacket.data[i]);
        UART_UartPutString(txData);
    }

    sprintf(txData,"ID:%x %x %x\r\n",receivedPacket.id >> 10, 
        (receivedPacket.id >> 6) & 0xF , receivedPacket.id & 0x3F);
    UART_UartPutString(txData);
}

uint16_t ReadCAN(CANPacket *receivedPacket){
    volatile int error = PollAndReceiveCANPacket(receivedPacket);
    if(!error){
        #ifdef CAN_LED
        CAN_LED_Write(LED_ON);
        #endif
        Can_LED = 0;
        return receivedPacket->data[0];
    }
    return NO_NEW_CAN_PACKET; //Means no Packet
}

void DisplayErrorCode(uint8_t code) {
    
    #ifdef ERROR_LED
    ERROR_LED_Write(LED_OFF);
    #endif
    #ifdef DEBUG_LED1   
    Debug_1_Write(LED_OFF);
    #endif
    
    Error_LED = 0;
    ERROR_LED_Write(LED_ON);
    
    #ifdef PRINT_MOTOR_ERROR
        //TODO: PRINT ERROR
    #endif

    switch(code)
    {   
        //case0: CAN Packet ERROR
        case 1://Mode Error
            #ifdef DEBUG_LED1
            Debug_1_Write(LED_ON);
            #endif
            break;
        default:
            //some error
            break;
    }

}

/* [] END OF FILE */