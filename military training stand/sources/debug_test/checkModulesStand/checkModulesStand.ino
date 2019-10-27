#include <EEPROM.h>
#include "MaxMatrix.h"

#define BLOCK_DELAY 0  // Bxx000000
#define LINE_DELAY 300 // Bxx111111

#define MODES_AMOUNT 21

#define DIN 12
#define LOAD 10
#define CLK 11
#define MAX_IN_USE 6

MaxMatrix matrix(DIN, LOAD, CLK, MAX_IN_USE);

int modulesArr[] = {   

// BLOCKS 21 blocks = 161B in range [50,211)                           

50,  // block_1_D_00_39
59,  // block_2_D_00_40
68,  // block_3a_D_53B_left
77,  // block_3b_D_53B_right
86,  // block_4a_MSHU_left
91,  // block_4b_MSHU_right
96,  // block_5a_D_55M_left
105, // block_5b_D_55M_right
114, // block_6_D_38A
123, // block_7_D_39
132, // block_8a_IL3_4_left
137, // block_8b_IL3_4_right
142, // block_9a_IO_3A_left
147, // block_9b_IO_3A_right
152, // block_10a_IO_3B_left
157, // block_10b_IO_3B_right
162, // block_11a_IT_A_left
167, // block_11b_IT_A_right
172, // block_12_IO_4
177, // block_13_D_00_31
194, // block_14_D_66
  
  
// LINES 70 lines = 614B in range [250,864)
  
250,  // D-53B(left) -> D-00-39
253,  // D-00-39 -> MSHU(left)
256,  // MSHU(left) -> D-55M(left)
263,  // D-55M(left) -> D-53B(left)
266,  // D-38A -> D-55M(left)
269,  // D-55M(left) -> D-38A
  
272,  // D-53B(right) -> D-00-40
275,  // D-00-40 -> MSHU(right)
278,  // MSHU(right) -> D-55M(right)
285,  // D-55M(right) -> D-53B(right)
288,  // D-38A -> D-55M(right)
291,  // D-55M(right) -> D-38A
  
294,  // D-38A -> D-39 // left
307,  // D-38A -> D-39 // right
  
320,  // D-39 -> D-38A // left
333,  // D-39 -> D-38A // right
  
346,  // D-39 -> IL3/4(left)
361,  // IL3/4(left) -> D-39
378,  // D-39 -> IL3/4(right)
393,  // IL3/4(right) -> D-39
  
410,  // IO-3A(left) -> D-39
421,  // IO-3A(right) -> D-39
432,  // D-39 -> IO-3B(left)
439,  // D-39 -> IO-3B(right)
  
446,  // D-39 -> IO-4
471,  // IO-4 -> D-39
  
496,  // D-39 -> D-00-31 // left
505,  // D-39 -> D-00-31 // right
  
514,  // D-00-31 -> D-39 // left
523,  // D-00-31 -> D-39 // right
  
532,  // D-39 -> D-66 // left
559,  // D-39 -> D-66 // right
586,  // D-66 -> D-39 // left
615,  // D-66 -> D-39 // right
  
644,  // D-66 -> IL3/4(left)
653,  // IL3/4(left) -> D-66
662,  // D-66 -> IL3/4(right)
671,  // IL3/4(right) -> D-66
  
680,  // D-00-31 -> IO-3A(left)
685,  // D-00-31 -> IO-3A(right)
690,  // IO-3B(left) -> D-00-31
695,  // IO-3B(right) -> D-00-31
  
700,  // D-00-31 -> IT/A(left) red
703,  // D-00-31 -> IT/A(left) blue
706,  // D-00-31 -> IT/A(right) red
709,  // D-00-31 -> IT/A(right) blue
  
712,  // IT/A(left) red -> D-00-31
715,  // IT/A(left) blue -> D-00-31
718,  // IT/A(right) red -> D-00-31
721,  // IT/A(right) blue -> D-00-31
  
724,  // D-00-31 -> D-66 // left
743,  // D-00-31 -> D-66 // right
  
762,  // D-66 -> D-00-31 // left
781,  // D-66 -> D-00-31 // right

800,  // D-66 -> RK(left) // red
805,  // D-66 -> RK(right) // red
810,  // RK(left) -> D-66 // blue
815,  // RK(right) -> D-66 // blue
  
820,  // D-66 -> P-296(left) // red
823,  // D-66 -> P-296(right) // red
826,  // D-66 -> P-296(left) // blue
829,  // D-66 -> P-296(right) // blue
  
832,  // D-66 -> PTRK 10x2(left) // red
839,  // D-66 -> PTRK 10x2(right) // red
846,  // D-66 -> PTRK 10x2(left) // blue
853   // D-66 -> PTRK 10x2(right) // blue
};

void turnOnModes(){
  for (int i = 0; i < MODES_AMOUNT; i++){
    matrix.setDot(EEPROM[i*2], EEPROM[i*2+1], true);
    delay(200);
    }  
  delay(1000);
  for (int i = 0; i < MODES_AMOUNT; i++){
    matrix.setDot(EEPROM[i*2], EEPROM[i*2+1], false);
    delay(200);
    }
}

// module - its address in EEPROM
void turnOnModule(int module){
  byte moduleHandler = EEPROM[module];
	int delayTime = ((moduleHandler & B11000000) == B10000000) ? BLOCK_DELAY : LINE_DELAY;
  byte moduleSize = moduleHandler & B00111111;

	// turn on
	for (int i = 0; i < moduleSize; i++){
		matrix.setDot(EEPROM[module + i*2 + 1], EEPROM[module + i*2 + 2], true); // +1 is offset from zero module hdr
		delay(delayTime);
	}
	delay(100);
	// turn of
	for (int i = 0; i < moduleSize; i++){
		matrix.setDot(EEPROM[module + i*2 + 1], EEPROM[module + i*2 + 2], false); // +1 is offset from zero module hdr
		delay(delayTime);
	}
}

void setup() {
  matrix.init();
  matrix.setIntensity(7);
  matrix.clear();
}

void loop(){
	turnOnModes();
	delay(1000);
	for (int i = 0; i < sizeof(modulesArr)/sizeof(int); i++){
		turnOnModule(modulesArr[i]);
		delay(700);
	}
}

/*
// debug
void loop(){
  turnOnModule(523); // 446 471 781 68 496 505 514 523
  /*
  int i=39, j=0;
  matrix.setDot(i, j, true);
  delay(300);
  matrix.setDot(i, j, false);
  delay(300);
  */
}
*/