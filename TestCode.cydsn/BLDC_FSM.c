#include "project.h"

// State of U, V, and W inductors high (polarity) and low (enable)
uint8_t UHstate = 0;
uint8_t ULstate = 0;
uint8_t VHstate = 0;
uint8_t VLstate = 0;
uint8_t WHstate = 0;
uint8_t WLstate = 0;

// Hall effect sensor binary data
uint8_t hall1State;
uint8_t hall2State;
uint8_t hall3State;

// FSM changing through states
// "--state = X" means "don't-care"
void readHallState() {
    hall1State = HALL1_Read();
    hall2State = HALL2_Read();
    hall3State = HALL3_Read();
    
	// State 1 (001)
	if (~hall1State && ~hall2State && hall3State) {
        UHstate = 1;
		ULstate = 1;
		// VHstate = X;
		VLstate = 0;
		WHstate = 0;
		WLstate = 1;
	}

	// State 2 (101)
	if (~hall1State && hall2State && hall3State) {
		// UHstate = X;
		ULstate = 0;
		VHstate = 1;
		VLstate = 0;
		WHstate = 0;
		WLstate = 1;
	}

	// State 3 (100)
	if (~hall1State && hall2State && hall3State) {
		UHstate = 0;
		ULstate = 1;
		VHstate = 1;
		VLstate = 1;
		// WHstate = X;
		WLstate = 0;
	}

    // State 4 (110)
    if (hall1State && ~hall2State && ~hall3State) {
		UHstate = 0;
		ULstate = 1;
		// VHstate = X;
		VLstate = 0;
		WHstate = 0;
		WLstate = 1;
    }
	    // State 5 (010)
    if (hall1State && ~hall2State && hall3State) {
		// UHstate = X;
		ULstate = 1;
		VHstate = 0;
		VLstate = 1;
		WHstate = 0;
		WLstate = 1;
    }
	    // State 6 (011)
    if (hall1State && hall2State && ~hall3State) {
		UHstate = 1;
		ULstate = 1;
		// VHstate = X;
		VLstate = 1;
		WHstate = 0;
		WLstate = 1;
    }
    
    UH_Write(UHstate);
    UL_Write(ULstate);
    VH_Write(VHstate);
    VL_Write(VLstate);
    WH_Write(WHstate);
    WL_Write(WLstate);
    
}
