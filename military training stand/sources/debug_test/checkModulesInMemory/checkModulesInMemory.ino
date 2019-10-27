#include <EEPROM.h>

#define BLOCK_DELAY 0
#define LINE_DELAY 300

#define MODES_AMOUNT 21

int modulesArr[] = { 	

// BLOCKS 21 blocks = 161B in range [50,211)

50,
59,
68,
77,
86,
91,
96,
105,
114,
123,
132,
137,
142,
147,
152,
157,
162,
167,
172,
177,
194,
	
	
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
803,  // D-66 -> RK(right) // red
806,  // D-66 -> RK(left) // blue
809,  // D-66 -> RK(right) // blue
	
812,  // RK(left) -> D-66 // red
815,  // RK(right) -> D-66 // red
818,  // RK(left) -> D-66 // blue
821,  // RK(right) -> D-66 // blue
	
824,  // D-66 -> P-296(left) // red
827,  // D-66 -> P-296(right) // red
830,  // D-66 -> P-296(left) // blue
833,  // D-66 -> P-296(right) // blue
	
836,  // D-66 -> PTRK 10x2(left) // red
843,  // D-66 -> PTRK 10x2(right) // red
850,  // D-66 -> PTRK 10x2(left) // blue
857   // D-66 -> PTRK 10x2(right) // blue
};

void turnOnModes(){
	for (int i = 0; i < MODES_AMOUNT; i++){
		Serial.print("[");
		Serial.print(i+1);
		Serial.print(": ");
		Serial.print(EEPROM[i*2]);
		Serial.print(", ");
		Serial.print(EEPROM[i*2+1]);
		Serial.print("] ");
		delay(500);
	}
	Serial.println("");
}

// module - its address in EEPROM
void turnOnModule(int module){
	int delayTime = (EEPROM[module] & B11000000 == B10000000) ? BLOCK_DELAY : LINE_DELAY;
	int moduleSize = EEPROM[module] & B00111111;
	
	Serial.print(EEPROM[module], BIN);
	Serial.print(": ");
	
	// turn on
	for (int i = 0; i < moduleSize; i++){
		Serial.print("[");
		Serial.print(EEPROM[module + i*2 + 1]); 
		Serial.print(", ");
		Serial.print(EEPROM[module + i*2 + 2]);
		Serial.print("] ");
		delay(delayTime);
	}
}

void setup() {
	Serial.begin(9600);
	
	turnOnModes();
	delay(1000);
	
	for (int i = 0; i < sizeof(modulesArr)/sizeof(int); i++){
		turnOnModule(modulesArr[i]);
		Serial.println("");
		delay(500);
	}
}

void loop(){
}
