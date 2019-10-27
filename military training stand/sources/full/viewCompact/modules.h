#ifndef _MODULES_
#define _MODULES_

	// MODES x21 = 42B in range [0;41]
	
	const uint16_t modes = 0;

	// BLOCKS x21 = 161B in range [50;210]
	
	const uint16_t block_1_D_00_39 = 50;
	const uint16_t block_2_D_00_40 = 59;
	const uint16_t block_3a_D_53B_left = 68;
	const uint16_t block_3b_D_53B_right = 77;
	const uint16_t block_4a_MSHU_left = 86;
	const uint16_t block_4b_MSHU_right = 91;
	const uint16_t block_5a_D_55M_left = 96;
	const uint16_t block_5b_D_55M_right = 105;
	const uint16_t block_6_D_38A = 114;
	const uint16_t block_7_D_39 = 123;
	const uint16_t block_8a_IL3_4_left = 132;
	const uint16_t block_8b_IL3_4_right = 137;
	const uint16_t block_9a_IO_3A_left = 142;
	const uint16_t block_9b_IO_3A_right = 147;
	const uint16_t block_10a_IO_3B_left = 152;
	const uint16_t block_10b_IO_3B_right = 157;
	const uint16_t block_11a_IT_A_left = 162;
	const uint16_t block_11b_IT_A_right = 167;
	const uint16_t block_12_IO_4 = 172;
	const uint16_t block_13_D_00_31 = 177;
	const uint16_t block_14_D_66 = 194;
	
	
	// LINES x70 = 610B in range [250;859]
	
	const uint16_t line_3a_1 = 250;                     // D-53B(left) -> D-00-39
	const uint16_t line_1_4a = 253;                     // D-00-39 -> MSHU(left)
	const uint16_t line_4a_5a = 256;                    // MSHU(left) -> D-55M(left)
	const uint16_t line_5a_3a = 263;                    // D-55M(left) -> D-53B(left)
	const uint16_t line_6_5a = 266;                     // D-38A -> D-55M(left)
	const uint16_t line_5a_6 = 269;                     // D-55M(left) -> D-38A
	
	const uint16_t line_3b_2 = 272;                     // D-53B(right) -> D-00-40
	const uint16_t line_2_4b = 275;                     // D-00-40 -> MSHU(right)
	const uint16_t line_4b_5b = 278;                    // MSHU(right) -> D-55M(right)
	const uint16_t line_5b_3b = 285;                    // D-55M(right) -> D-53B(right)
	const uint16_t line_6_5b = 288;                     // D-38A -> D-55M(right)
	const uint16_t line_5b_6 = 291;                     // D-55M(right) -> D-38A
	
	const uint16_t line_6_7_left = 294;                 // D-38A -> D-39 // left
	const uint16_t line_6_7_right = 307;                // D-38A -> D-39 // right
	
	const uint16_t line_7_6_left = 320;                 // D-39 -> D-38A // left
	const uint16_t line_7_6_right = 333;                // D-39 -> D-38A // right
	
	const uint16_t line_7_8a = 346;                     // D-39 -> IL3/4(left)
	const uint16_t line_8a_7 = 361;                     // IL3/4(left) -> D-39
	const uint16_t line_7_8b = 378;                     // D-39 -> IL3/4(right)
	const uint16_t line_8b_7 = 393;                     // IL3/4(right) -> D-39
	
	const uint16_t line_9a_7 = 410;                     // IO-3A(left) -> D-39
	const uint16_t line_9b_7 = 421;                     // IO-3A(right) -> D-39
	const uint16_t line_7_10a = 432;                    // D-39 -> IO-3B(left)
	const uint16_t line_7_10b = 439;                    // D-39 -> IO-3B(right)
	
	const uint16_t line_7_12 = 446;                     // D-39 -> IO-4
	const uint16_t line_12_7 = 471;                     // IO-4 -> D-39
	
	const uint16_t line_7_13_left = 496;                // D-39 -> D-00-31 // left
	const uint16_t line_7_13_right = 505;               // D-39 -> D-00-31 // right
	
	const uint16_t line_13_7_left = 514;                // D-00-31 -> D-39 // left
	const uint16_t line_13_7_right = 523;               // D-00-31 -> D-39 // right
	
	const uint16_t line_7_14_left = 532;                // D-39 -> D-66 // left
	const uint16_t line_7_14_right = 559;               // D-39 -> D-66 // right
	const uint16_t line_14_7_left = 586;                // D-66 -> D-39 // left
	const uint16_t line_14_7_right = 615;               // D-66 -> D-39 // right
	
	const uint16_t line_14_8a = 644;                    // D-66 -> IL3/4(left)
	const uint16_t line_8a_14 = 653;                    // IL3/4(left) -> D-66
	const uint16_t line_14_8b = 662;                    // D-66 -> IL3/4(right)
	const uint16_t line_8b_14 = 671;                    // IL3/4(right) -> D-66
	
	const uint16_t line_13_9a = 680;                    // D-00-31 -> IO-3A(left)
	const uint16_t line_13_9b = 685;                    // D-00-31 -> IO-3A(right)
	const uint16_t line_10a_13 = 690;                   // IO-3B(left) -> D-00-31
	const uint16_t line_10b_13 = 695;                   // IO-3B(right) -> D-00-31
	
	const uint16_t line_13_11a_red = 700;               // D-00-31 -> IT/A(left) red
	const uint16_t line_13_11a_blue = 703;              // D-00-31 -> IT/A(left) blue
	const uint16_t line_13_11b_red = 706;               // D-00-31 -> IT/A(right) red
	const uint16_t line_13_11b_blue = 709;              // D-00-31 -> IT/A(right) blue
	
	const uint16_t line_11a_13_red = 712;               // IT/A(left) red -> D-00-31
	const uint16_t line_11a_13_blue = 715;              // IT/A(left) blue -> D-00-31
	const uint16_t line_11b_13_red = 718;               // IT/A(right) red -> D-00-31
	const uint16_t line_11b_13_blue = 721;              // IT/A(right) blue -> D-00-31
	
	const uint16_t line_13_14_left = 724;               // D-00-31 -> D-66 // left
	const uint16_t line_13_14_right = 743;              // D-00-31 -> D-66 // right
	
	const uint16_t line_14_13_left = 762;               // D-66 -> D-00-31 // left
	const uint16_t line_14_13_right = 781;              // D-66 -> D-00-31 // right
	
	const uint16_t line_14_RK_left_red = 800;           // D-66 -> RK(left) // red
	const uint16_t line_14_RK_right_red = 805;          // D-66 -> RK(right) // red
	const uint16_t line_RK_14_left_blue = 810;          // RK(left) -> D-66 // blue
	const uint16_t line_RK_14_right_blue = 815;         // RK(right) -> D-66 // blue
  
	const uint16_t line_14_P_296_left_red = 820;        // D-66 -> P-296(left) // red
	const uint16_t line_14_P_296_right_red = 823;       // D-66 -> P-296(right) // red
	const uint16_t line_14_P_296_left_blue = 826;       // D-66 -> P-296(left) // blue
	const uint16_t line_14_P_296_right_blue = 829;      // D-66 -> P-296(right) // blue
	
	const uint16_t line_14_PTRK_10x2_left_red = 832;    // D-66 -> PTRK 10x2(left) // red
	const uint16_t line_14_PTRK_10x2_right_red = 839;   // D-66 -> PTRK 10x2(right) // red
	const uint16_t line_14_PTRK_10x2_left_blue = 846;   // D-66 -> PTRK 10x2(left) // blue
	const uint16_t line_14_PTRK_10x2_right_blue = 853;  // D-66 -> PTRK 10x2(right) // blue

#endif
