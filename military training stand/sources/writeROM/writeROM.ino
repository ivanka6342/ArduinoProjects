#include <EEPROM.h>

#define dataSize 817

#define modesDataSegment 0
#define blockDataSegment 50
#define linesDataSegment 250

#define modesDataSize 42
#define blockDataSize 161
#define linesDataSize 614

uint8_t modesDataArr[modesDataSize] = {
	47,6, 47,7, 46,7, 46,6, 46,5, 46,3, 45,7, 45,6, 41,7, 41,6, 41,5, 45,5, 45,4, 45,3, 45,2, 45,1, 44,7, 44,6, 44,5, 44,4, 42,4
};

// mask B10xxxxxx
uint8_t blockDataArr[blockDataSize] = {
	B10000100, 47,5, 41,4, 41,2, 47,4,                  // block_1_D_00_39
	B10000100, 19,5, 22,6, 19,6, 21,1,                  // block_2_D_00_40
	B10000100, 47,3, 46,1, 47,0, 47,1,                  // block_3a_D_53B_left
	B10000100, 19,1, 19,3, 17,3, 22,5,                  // block_3b_D_53B_right
	B10000010, 41,0, 46,0,                              // block_4a_MSHU_left
	B10000010, 21,0, 21,7,                              // block_4b_MSHU_right
	B10000100, 37,0, 38,0, 36,0, 37,1,                  // block_5a_D_55M_left
	B10000100, 22,0, 22,1, 22,2, 22,3,                  // block_5b_D_55M_right
	B10000100, 24,0, 25,0, 31,1, 29,0,                  // block_6_D_38A
	B10000100, 39,2, 31,2, 31,6, 37,4,                  // block_7_D_39
	B10000010, 43,7, 32,3,                              // block_8a_IL3_4_left
	B10000010, 9,0, 9,1,                                // block_8b_IL3_4_right
	B10000010, 33,3, 39,0,                              // block_9a_IO_3A_left
	B10000010, 11,4, 11,6,                              // block_9b_IO_3A_right
	B10000010, 34,3, 36,3,                              // block_10a_IO_3B_left
	B10000010, 8,5, 11,5,                               // block_10b_IO_3B_right
	B10000010, 35,6, 38,6,                              // block_11a_IT_A_left
	B10000010, 15,2, 13,2,                              // block_11b_IT_A_right
	B10000010, 38,5, 37,5,                              // block_12_IO_4
	B10001000, 1,7, 3,6, 2,6, 7,6, 6,5, 7,0, 0,1, 4,6,  // block_13_D_00_31
	B10001000, 0,6, 1,2, 1,1, 6,4, 7,7, 7,1, 4,5, 12,3  // block_14_D_66
};
	
// mask B01xxxxxx
uint8_t linesDataArr[linesDataSize] = {	
	// line_3a_1                      // D-53B(left) -> D-00-39
	B01000001, 46,4,
	// line_1_4a                      // D-00-39 -> MSHU(left)
	B01000001, 41,1,
	// line_4a_5a                     // MSHU(left) -> D-55M(left)
	B01000011, 46,2, 44,0, 45,0,
	// line_5a_3a                     // D-55M(left) -> D-53B(left)
	B01000001, 47,2,
	// line_6_5a                      // D-38A -> D-55M(left)
	B01000001, 39,1,
	// line_5a_6                      // D-55M(left) -> D-38A
	B01000001, 38,1,
	
	// line_3b_2                      // D-53B(right) -> D-00-40
	B01000001, 18,3,
	// line_2_4b                      // D-00-40 -> MSHU(right)
	B01000001, 21,3,
	// line_4b_5b                     // MSHU(right) -> D-55M(right)
	B01000011, 17,0, 18,0, 19,0,
	// line_5b_3b                     // D-55M(right) -> D-53B(right)
	B01000001, 22,7,
	// line_6_5b                      // D-38A -> D-55M(right)
	B01000001, 30,0,
	// line_5b_6                      // D-55M(right) -> D-38A
	B01000001, 31,0,
	
	// line_6_7_left                  // D-38A -> D-39 // left
	B01000110, 27,1, 24,2, 27,3, 26,1, 25,2, 28,3,
	// line_6_7_right                 // D-38A -> D-39 // right
	B01000110, 26,0, 26,2, 29,3, 27,0, 27,2, 30,3,

	// line_7_6_left                  // D-39 -> D-38A // left
	B01000110, 24,3, 25,1, 29,1, 26,3, 24,1, 28,1,
	// line_7_6_right                 // D-39 -> D-38A // right
	B01000110, 31,3, 28,2, 28,0, 30,2, 29,2, 30,1,
	
	// line_7_8a                      // D-39 -> IL3/4(left)
	B01000111, 38,3, 35,2, 37,2, 36,1, 34,1, 32,0, 33,2,
	// line_8a_7                      // IL3/4(left) -> D-39
	B01001000, 32,2, 32,1, 33,1, 33,0, 34,0, 38,2, 36,2, 39,3,
	// line_7_8b                      // D-39 -> IL3/4(right)
	B01000111, 19,7, 23,4, 20,4, 20,7, 20,1, 17,5, 16,3,
	// line_8b_7                      // IL3/4(right) -> D-39
	B01001000, 20,3, 16,5, 18,5, 16,1, 16,7, 16,4, 20,0, 17,7,

	// line_9a_7                      // IO-3A(left) -> D-39
	B01000101, 34,2, 35,1, 34,4, 35,3, 37,3,
	// line_9b_7                      // IO-3A(right) -> D-39
	B01000101, 20,2, 23,7, 21,2, 21,4, 17,2,
	// line_7_10a                     // D-39 -> IO-3B(left)
	B01000011, 36,4, 35,0, 35,4,
	// line_7_10b                     // D-39 -> IO-3B(right)
	B01000011, 18,7, 17,4, 18,4,
	
	// line_7_12                      // D-39 -> IO-4
  B01001100, 24,7, 25,6, 24,6, 25,7, 26,6, 24,5, 26,7, 27,6, 25,5, 27,7, 26,5, 27,5,
	// line_12_7                      // IO-4 -> D-39
	B01001100, 25,4, 30,5, 31,7, 24,4, 30,7, 30,6, 27,4, 29,5, 29,6, 26,4, 28,6, 28,5,

	// line_7_13_left                 // D-39 -> D-00-31 // left
	B01000100, 39,4, 35,5, 39,5, 39,6,
	// line_7_13_right                // D-39 -> D-00-31 // right
	B01000100, 28,7, 25,3, 31,5, 28,4,

	// line_13_7_left                 // D-00-31 -> D-39 // left
	B01000100, 39,7, 37,6, 36,5, 38,4,
	// line_13_7_right                // D-00-31 -> D-39 // right
	B01000100, 29,4, 30,4, 31,4, 29,7,
	
	// line_7_14_left                 // D-39 -> D-66 // left
	B01001101, 22,4, 43,3, 43,4, 43,0, 43,1, 40,2, 40,4, 43,5, 43,6, 44,1, 44,3, 44,2, 42,2,
	// line_7_14_right                // D-39 -> D-66 // right
	B01001101, 19,2, 18,1, 16,0, 16,2, 23,3, 23,5, 21,6, 16,6, 20,5, 9,3, 8,3, 13,3, 14,3,
	// line_14_7_left                 // D-66 -> D-39 // left
	B01001110, 42,5, 42,7, 42,6, 42,3, 40,7, 41,3, 40,6, 40,5, 40,3, 40,1, 40,0, 42,1, 42,0, 43,2,
	// line_14_7_right                // D-66 -> D-39 // right
	B01001110, 12,1, 14,1, 15,1, 13,1, 20,6, 23,6, 17,6, 18,6, 21,5, 23,1, 23,2, 23,0, 17,1, 18,2,

	// line_14_8a                     // D-66 -> IL3/4(left)
	B01000100, 32,7, 32,6, 32,5, 32,4,
	// line_8a_14                     // IL3/4(left) -> D-66
	B01000100, 33,4, 33,5, 33,6, 33,7,
	// line_14_8b                     // D-66 -> IL3/4(right)
	B01000100, 14,7, 13,7, 8,7, 9,7,
	// line_8b_14                     // IL3/4(right) -> D-66
	B01000100, 9,6, 8,6, 10,7, 14,6,

	// line_13_9a                     // D-00-31 -> IO-3A(left)
	B01000010, 34,7, 34,6,
	// line_13_9b                     // D-00-31 -> IO-3A(right)
	B01000010, 10,6, 9,5,
	// line_10a_13                    // IO-3B(left) -> D-00-31
	B01000010, 34,5, 36,6,
	// line_10b_13                    // IO-3B(right) -> D-00-31
	B01000010, 10,5, 15,3,

	// line_13_11a_red                // D-00-31 -> IT/A(left) red
	B01000001, 35,7,
	// line_13_11a_blue               // D-00-31 -> IT/A(left) blue
	B01000001, 36,7,
	// line_13_11b_red                // D-00-31 -> IT/A(right) red
	B01000001, 15,0,
	// line_13_11b_blue               // D-00-31 -> IT/A(right) blue
	B01000001, 15,7,

	// line_11a_13_red                // IT/A(left) red -> D-00-31
	B01000001, 38,7,
	// line_11a_13_blue               // IT/A(left) blue -> D-00-31
	B01000001, 37,7,
	// line_11b_13_red                // IT/A(right) red -> D-00-31
	B01000001, 15,4,
	// line_11b_13_blue               // IT/A(right) blue -> D-00-31
	B01000001, 13,5,

	// line_13_14_left                // D-00-31 -> D-66 // left
	B01001001, 1,6, 1,3, 3,3, 0,3, 2,3, 5,3, 7,3, 6,3, 4,3,
  // line_13_14_right               // D-00-31 -> D-66 // right
	B01001001, 7,5, 7,4, 4,2, 4,7, 4,1, 4,0, 6,7, 0,2, 6,2,

	// line_14_13_left                // D-66 -> D-00-31 // left
	B01001001, 2,5, 2,0, 0,5, 5,2, 1,4, 5,4, 5,5, 3,5, 1,5,
	// line_14_13_right               // D-66 -> D-00-31 // right
	B01001001, 7,2, 3,4, 2,1, 2,7, 2,2, 6,6, 2,4, 0,7, 4,4,
	
	// line_14_RK_left_red            // D-66 -> RK(left) // red
	B01000010, 3,7, 5,6,
	// line_14_RK_right_red           // D-66 -> RK(right) // red
	B01000010, 12,4, 12,0,
	// line_RK_14_left_blue           // RK(left) -> D-66 // blue
	B01000010, 0,0, 1,0,
	// line_RK_14_right_blue          // RK(right) -> D-66 // blue
	B01000010, 12,7, 12,2,
	
	// line_14_P_296_left_red         // D-66 -> P-296(left) // red
	B01000001, 5,7,
	// line_14_P_296_right_red        // D-66 -> P-296(right) // red
	B01000001, 12,5,
	// line_14_P_296_left_blue        // D-66 -> P-296(left) // blue
	B01000001, 0,4,
	// line_14_P_296_right_blue       // D-66 -> P-296(right) // blue
	B01000001, 12,6,

	// line_14_PTRK_10x2_left_red     // D-66 -> PTRK 10x2(left) // red
	B01000011, 3,0, 5,0, 6,0,
	// line_14_PTRK_10x2_right_red    // D-66 -> PTRK 10x2(right) // red
	B01000011, 15,6, 14,0, 14,2,
	// line_14_PTRK_10x2_left_blue    // D-66 -> PTRK 10x2(left) // blue
	B01000011, 3,1, 5,1, 6,1,
	// line_14_PTRK_10x2_right_blue   // D-66 -> PTRK 10x2(right) // blue
	B01000011, 14,4, 15,5, 14,5
};

void setup() {
	Serial.begin(9600);
	
	uint16_t i = 0;
	while(i < modesDataSize){
		EEPROM[modesDataSegment+i] = modesDataArr[i];
		i++;
	}
	
	i = 0;
	while(i < blockDataSize){
		EEPROM[blockDataSegment+i] = blockDataArr[i];
		i++;
	}
	
	i = 0;
	while(i < linesDataSize){
		EEPROM[linesDataSegment+i] = linesDataArr[i];
		i++;
	}
}

void loop() {
}
