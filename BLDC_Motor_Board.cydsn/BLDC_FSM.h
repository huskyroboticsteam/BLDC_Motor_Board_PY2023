#ifndef BLDC_FSM_H
    #define BLDC_FSM_H
    #include <stdint.h>

    //States in FSM
    #define UNINIT          0xFF
    #define SET_PWM         0x0
    #define CALC_PID        0x1
    #define CHECK_CAN       0x2
    #define QUEUE_ERROR     0x3
    
    void GotoUninitState();
    void SetStateTo(uint8_t state);
    void SetModeTo(uint8_t mode);
    uint8_t GetState();
    uint8_t GetMode();
    
    void PositionConstIsSet();
    void IntegralConstIsSet();
    void DerivativeConstIsSet();
    void PPJRConstIsSet();
    void MaxJointRevIsSet();
    uint8_t PIDconstsSet();
    void ClearPIDconst();
    
#endif