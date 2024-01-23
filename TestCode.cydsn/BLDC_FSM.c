#include "project.h"

/* [] END OF FILE */
uint8_t UHstate = 0;
uint8_t ULstate = 0;
uint8_t VHstate = 0;
uint8_t VLstate = 0;

void readHallState() {
	// State 1 (001)
	if (~HALL1_read() && ~HALL2_read() && HALL3_read()) {
		UH = 1
		UL = 1
		// VH = X
		VL = 0
		WH = 0
		WL = 1
	}

	// State 2 (101)
	if (~HALL1_read() && HALL2_read() && ~HALL3_read()) {
		// UH = X
		UL = 0
		VH = 1
		VL = 0
		WH = 0
		WL = 1
	}

	// State 3 (100)
	if (~HALL1 && HALL2 && HALL3) {
		UH = 0
		UL = 1
		VH = 1
		VL = 1
		// WH = X
		WL = 0
	}

    // State 4 (110)
    if (HALL1 && ~HALL2 && ~HALL3) {
		UH = 0
		UL = 1
		// VH = X
		VL = 0
		WH = 0
		WL = 1
    }
	    // State 5 (010)
    if (HALL1 && ~HALL2 && HALL3) {
		// UH = X
		UL = 1
		VH = 0
		VL = 1
		WH = 0
		WL = 1

	    // State 6 (011)
    if (HALL1 && HALL2 && ~HALL3) {
		UH = 1
		UL = 1
		// VH = X
		VL = 1
		WH = 0
		WL = 1
    }
}
