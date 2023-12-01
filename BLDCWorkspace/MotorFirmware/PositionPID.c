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

#include "Motor_Unit_Debug.h"
#include <project.h>
#include "PositionPID.h"
#include "MotorDrive.h"
#include "main.h"
#include <math.h>

int32_t PWM = 0;
int32_t kPosition = 0, kIntegral = 0, kDerivative = 0;
int32_t tickMax = 0, tickMin = 0, mDegMax = 0, mDegMin = 0;
int8 flipEncoder = 1;
double mDegPerTick = 0.0;

int integral = 0;     //needs to be reset upon mode change
int lastError = 0;    //needs to be reset upon mode change
int integralClamp = 5000;
int32 maxPWM = 32767;

// double ratio;
// uint8 complete = 0;

uint8_t usingPot = 0;
uint8_t enabledPID = 0;

extern uint8_t ignoreLimSw;
extern char txData[TX_DATA_SIZE];

void ClearPIDProgress() {
    integral = 0;
    lastError = 0;
}
void DisablePID() {
    enabledPID = 0;
}
void EnablePID() {
    enabledPID = 1;
}
uint8_t PIDIsEnabled() {
    return(enabledPID);
}
void InitializePID() {
    set_PWM(0, 0, 0);
    ClearPIDProgress();
    DisablePID();
    lastError = 0;
}

int32_t GetPotVal() {
    int32_t n = 1000;
    int32_t sum = 0;
    for (int i = 0; i < n; i++) {
        ADC_Pot_StartConvert();
        ADC_Pot_IsEndConversion(ADC_Pot_WAIT_FOR_RESULT);
        sum += ADC_Pot_GetResult16(0);
    }    
    return sum/n;
}

double UpdateConversion() {
    if (mDegMin == mDegMax) return 0;
    mDegPerTick = (double) (mDegMax-mDegMin)/(tickMax-tickMin);
    return mDegPerTick;
}

int32_t GetMaxPIDPWM(){ return maxPWM; }
int32_t GetkPosition(){ return kPosition; }
int32_t GetkIntegral(){ return kIntegral; }
int32_t GetkDerivative(){ return kDerivative; }
double GetConversion(){ return mDegPerTick; }
int32_t GetTickMax(){ return tickMax; }
int32_t GetTickMin(){ return tickMin; }
int32_t GetmDegMax(){ return mDegMax; }
int32_t GetmDegMin(){ return mDegMin; }
uint8_t GetUsingPot(){ return usingPot; }

void SetMaxPIDPWM(uint16_t setValue){ maxPWM = setValue; }
void SetkPosition(int32_t kP){ kPosition = kP; }
void SetkIntegral(int32_t kI){ kIntegral = kI; }
void SetkDerivative(int32_t kD){ kDerivative = kD; }
void setTickMin(int32_t val){ tickMin = val; }
void setTickMax(int32_t val){ tickMax = val; }
void setmDegMin(int32_t val){ mDegMin = val; }
void setmDegMax(int32_t val){ mDegMax = val; }
void setUsingPot(uint8_t pot){ usingPot = pot; }
void SetConversion(double conv){ mDegPerTick = conv; }

void SetEncoderDir(uint8_t flip){
    flipEncoder = (flip ? -1 : 1);
}

void setEncoderAtLimit(int enc_limit){
    QuadDec_SetCounter((int)round(enc_limit * flipEncoder / mDegPerTick));    
}

int32_t GetPositionmDeg() {
    if (mDegPerTick == 0.0)
        return(0);
    
    if (usingPot) {
        return (GetPotVal()-tickMin) * mDegPerTick + mDegMin;
    } else {
        return QuadDec_GetCounter() * mDegPerTick * flipEncoder;
        // return 0 * mDegPerTick;
    }
}
void SetPosition(int32_t mDegs) {
        //TODO: Make Potentiometer Compatible
        PWM = Position_PID(mDegs);
        
        //Max Power clamp
        if(PWM > maxPWM){
            set_PWM(maxPWM, ignoreLimSw, Status_Reg_Switches_Read());   
        } else if(PWM < -maxPWM) {
            set_PWM(-maxPWM, ignoreLimSw, Status_Reg_Switches_Read());
        } else {
            set_PWM(PWM, ignoreLimSw, Status_Reg_Switches_Read());   
        }
}

int32_t Position_PID(int32 targetmDeg){
        
    if(!PIDIsEnabled()){
        return(0);
    }
    
    int32 current = GetPositionmDeg();
    int32 error = targetmDeg - current;
    
    //if within tolerance exit
    if(error <= 5 && error >= -5) {
      return(0);
    }
    
    integral = integral + error;
    
    //integral clamp
    if (integral > integralClamp) {
        integral = integralClamp;   
    }
    if (integral < -integralClamp) {
        integral = -integralClamp;
    }
    
    int derivative = error - lastError;
    int PWMOut = error*kPosition/10 + integral*kIntegral/10 + derivative*kDerivative/10;
    lastError = error;
    
    #ifdef PRINT_PID_DEBUG
        sprintf(txData,"c:%li, P:%li, I%d, D:%d, Out:%d Time:%lu\n\r", current, error, integral, derivative, PWMOut, Timer_PWM_ReadCounter());
        UART_UartPutString(txData);   
    #endif
 
    return (PWMOut);
}

/* [] END OF FILE */
