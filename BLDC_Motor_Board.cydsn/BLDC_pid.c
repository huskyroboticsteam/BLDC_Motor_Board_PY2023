
// ---------------------------------------------------use delay instead of PWM--------------------------------

// #include "Motor_Unit_Debug.h"
#include <project.h>
#include "BLDC_pid.h"
#include "BLDC_Drive.h"
#include "main.h"
#include <math.h>

int32_t delayTime = 1000;
// int32_t PWM = 0;
int32_t kPosition = 0, kIntegral = 0, kDerivative = 0;
int32_t tickMax = 0, tickMin = 0, mDegMax = 0, mDegMin = 0;
double mDegPerTick = 0.0;

int integral = 0;     //needs to be reset upon mode change
int lastError = 0;    //needs to be reset upon mode change
int integralClamp = 5000;

// double ratio;
// uint8 complete = 0;

uint8_t enabledPID = 0;

uint32_t maxSpeed = 32768;

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
    // set_PWM(0, 0, 0);
    ClearPIDProgress();
    DisablePID();
    lastError = 0;
}

double UpdateConversion() {
    if (mDegMin == mDegMax) return 0;
    mDegPerTick = (double) (mDegMax-mDegMin)/(tickMax-tickMin);
    return mDegPerTick;
}

int32_t GetMaxPIDSpeed(){ return maxSpeed; }
int32_t GetkPosition(){ return kPosition; }
int32_t GetkIntegral(){ return kIntegral; }
int32_t GetkDerivative(){ return kDerivative; }
double GetConversion(){ return mDegPerTick; }
int32_t GetTickMax(){ return tickMax; }
int32_t GetTickMin(){ return tickMin; }
int32_t GetmDegMax(){ return mDegMax; }
int32_t GetmDegMin(){ return mDegMin; }

void SetMaxPIDSpeed(uint16_t setValue){ maxSpeed = setValue; }
void SetkPosition(int32_t kP){ kPosition = kP; }
void SetkIntegral(int32_t kI){ kIntegral = kI; }
void SetkDerivative(int32_t kD){ kDerivative = kD; }
void setTickMin(int32_t val){ tickMin = val; }
void setTickMax(int32_t val){ tickMax = val; }
void setmDegMin(int32_t val){ mDegMin = val; }
void setmDegMax(int32_t val){ mDegMax = val; }
void SetConversion(double conv){ mDegPerTick = conv; }

// void SetEncoderDir(uint8_t flip){
//     flipEncoder = (flip ? -1 : 1);
// }

// void setEncoderAtLimit(int enc_limit){
    // TODO   
// }

int32_t GetPositionmDeg() {
    if (mDegPerTick == 0.0)
        return(0);
    // TODO
    return 0;
}

void SetPosition(int32_t mDegs) {       
        set_speed(Position_PID(mDegs), ignoreLimSw);   
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
