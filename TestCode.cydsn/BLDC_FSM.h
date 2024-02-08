#ifndef BLDC_FSM_H
    #define BLDC_FSM_H
    #include <stdint.h>
    
    // states in FSM
    #define hallState 0x0
    #define UVWState  0x1
    /*--------------------------------------------------*/
    
    // Declare functions
    void readHallState();
    
    
#endif
       
    
    
    
    