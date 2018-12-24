#ifndef _MODULES_
#define _MODULES_

#define BLOCK_DELAY 0
#define LINE_DELAY 100

#include "dot_index.h"

typedef struct moduleStruct {
  byte dotDelay;
  byte dotCount;
  int* dotArray;
} module;


//////////////////////// blocks ////////////////////////

int arr_1 [] = {-1, 0, 1, 2};
module block_1_D_00_39 = {BLOCK_DELAY, 4, arr_1};                       // D-00-39

int arr_2 [] = {3, 4, 5, 6};
module block_2_D_00_40 = {BLOCK_DELAY, 4, arr_2};                       // D-00-40

int arr_3a [] = {7, 8, 9, 10};
module block_3a_D_53B_left = {BLOCK_DELAY, 4, arr_3a};                  // D-53B(left)

int arr_3b [] = {11, 12, 13, 14};
module block_3b_D_53B_right = {BLOCK_DELAY, 4, arr_3b};                 // D-53B(right)

int arr_4a [] = {15, 16};
module block_4a_MSHU_left = {BLOCK_DELAY, 2, arr_4a};                   // MSHU(left)

int arr_4b [] = {17, 18};
module block_4b_MSHU_right = {BLOCK_DELAY, 2, arr_4b};                  // MSHU(right)

int arr_5a [] = {19, 20, 21, 22};
module block_5a_D_55M_left = {BLOCK_DELAY, 4, arr_5a};                  // D-55M(left)

int arr_5b [] = {23, 24, 25, 26};
module block_5b_D_55M_right = {BLOCK_DELAY, 4, arr_5b};                 // D-55M(right)

int arr_6 [] = {27, 28, 29, 30};
module block_6_D_38A = {BLOCK_DELAY, 4, arr_6};                         // D-38A

int arr_7 [] = {31, 32, 33, 34};
module block_7_D_39 = {BLOCK_DELAY, 4, arr_7};                          // D-39

int arr_8a [] = {35, 36};
module block_8a_IL3_4_left = {BLOCK_DELAY, 2, arr_8a};                  // IL3/4(left)

int arr_8b [] = {37, 38};
module block_8b_IL3_4_right = {BLOCK_DELAY, 2, arr_8b};                 // IL3/4(right)

int arr_9a [] = {39, 40};
module block_9a_IO_3A_left = {BLOCK_DELAY, 2, arr_9a};                  // IO-3A(left)

int arr_9b [] = {41, 42};
module block_9b_IO_3A_right = {BLOCK_DELAY, 2, arr_9b};                 // IO-3A(right)

int arr_10a [] = {43, 44};
module block_10a_IO_3B_left = {BLOCK_DELAY, 2, arr_10a};                // IO-3B(left)

int arr_10b [] = {45, 46};
module block_10b_IO_3B_right = {BLOCK_DELAY, 2, arr_10b};               // IO-3B(right)

int arr_11a [] = {47, 48};
module block_11a_IT_A_left = {BLOCK_DELAY, 2, arr_11a};                 // IT/A(left)

int arr_11b [] = {49, 50};
module block_11b_IT_A_right = {BLOCK_DELAY, 2, arr_11b};                // IT/A(right)

int arr_12 [] = {51, 52};
module block_12_IO_4 = {BLOCK_DELAY, 2, arr_12};                        // IO-4

int arr_13 [] = {53, 54, 55, 56, 57, 58, 59, 60};
module block_13_D_00_31 = {BLOCK_DELAY, 8, arr_13};                     // D-00-31

int arr_14 [] = {61, 62, 63, 64, 65, 66, 67, 68};
module block_14_D_66 = {BLOCK_DELAY, 8, arr_14};                        // D-66


//////////////////////// lines ////////////////////////

int arr_3a_1 [] = {69};
module line_3a_1 = {LINE_DELAY, 1, arr_3a_1};                  // D-53B(left) -> D-00-39
int arr_1_4a [] = {70};
module line_1_4a = {LINE_DELAY, 1, arr_1_4a};                  // D-00-39 -> MSHU(left)
int arr_4a_5a [] = {71, 72, 73};
module line_4a_5a = {LINE_DELAY, 3, arr_4a_5a};                // MSHU(left) -> D-55M(left)
int arr_5a_3a [] = {74};
module line_5a_3a = {LINE_DELAY, 1, arr_5a_3a};                // D-55M(left) -> D-53B(left)
int arr_6_5a [] = {75};
module line_6_5a = {LINE_DELAY, 1, arr_6_5a};                  // D-38A -> D-55M(left)
int arr_5a_6 [] = {76};
module line_5a_6 = {LINE_DELAY, 1, arr_5a_6};                  // D-55M(left) -> D-38A

int arr_3b_2 [] = {77};
module line_3b_2 = {LINE_DELAY, 1, arr_3b_2};                  // D-53B(right) -> D-00-40
int arr_2_4b [] = {78};
module line_2_4b = {LINE_DELAY, 1, arr_2_4b};                  // D-00-40 -> MSHU(right)
int arr_4b_5b [] = {79, 80, 81};
module line_4b_5b = {LINE_DELAY, 3, arr_4b_5b};                // MSHU(right) -> D-55M(right)
int arr_5b_3b [] = {82};
module line_5b_3b = {LINE_DELAY, 1, arr_5b_3b};                // D-55M(right) -> D-53B(right)
int arr_6_5b [] = {83};
module line_6_5b = {LINE_DELAY, 1, arr_6_5b};                  // D-38A -> D-55M(right)
int arr_5b_6 [] = {84};
module line_5b_6 = {LINE_DELAY, 1, arr_5b_6};                  // D-55M(right) -> D-38A

int arr_6_7_left [] = {85, 86, 87, 88, 89, 90};
module line_6_7_left = {LINE_DELAY, 6, arr_6_7_left};          // D-38A -> D-39 // left
int arr_6_7_right [] = {91, 92, 93, 94, 95, 96};
module line_6_7_right = {LINE_DELAY, 6, arr_6_7_right};        // D-38A -> D-39 // right

int arr_7_6_left [] = {97, 98, 99, 100, 101, 102};
module line_7_6_left = {LINE_DELAY, 6, arr_7_6_left};          // D-39 -> D-38A // left
int arr_7_6_right [] = {103, 104, 105, 106, 107, 108};
module line_7_6_right = {LINE_DELAY, 6, arr_7_6_right};        // D-39 -> D-38A // right

int arr_7_8a [] = {109, 110, 111, 112, 113, 114, 115};
module line_7_8a = {LINE_DELAY, 7, arr_7_8a};                  // D-39 -> IL3/4(left)
int arr_8a_7 [] = {116, 117, 118, 119, 120, 121, 122, 123};
module line_8a_7 = {LINE_DELAY, 8, arr_8a_7};                  // IL3/4(left) -> D-39
int arr_7_8b [] = {124, 125, 126, 127, 128, 129, 130};
module line_7_8b = {LINE_DELAY, 7, arr_7_8b};                  // D-39 -> IL3/4(right)
int arr_8b_7 [] = {131, 132, 133, 134, 135, 136, 137, 138};
module line_8b_7 = {LINE_DELAY, 8, arr_8b_7};                  // IL3/4(right) -> D-39

int arr_9a_7 [] = {139, 140, 141, 142, 143};
module line_9a_7 = {LINE_DELAY, 5, arr_9a_7};                  // IO-3A(left) -> D-39
int arr_9b_7 [] = {144, 145, 146, 147, 148};
module line_9b_7 = {LINE_DELAY, 5, arr_9b_7};                  // IO-3A(right) -> D-39
int arr_7_10a [] = {149, 150, 151};
module line_7_10a = {LINE_DELAY, 3, arr_7_10a};                // D-39 -> IO-3B(left)
int arr_7_10b [] = {152, 153, 154};
module line_7_10b = {LINE_DELAY, 3, arr_7_10b};                // D-39 -> IO-3B(right)

int arr_7_12 [] = {155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166};
module line_7_12 = {LINE_DELAY, 12, arr_7_12};                 // D-39 -> IO-4
int arr_12_7 [] = {167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178};
module line_12_7 = {LINE_DELAY, 12, arr_12_7};                 // IO-4 -> D-39

int arr_7_13_left [] = {179, 180, 181, 182};
module line_7_13_left = {LINE_DELAY, 4, arr_7_13_left};        // D-39 -> D-00-31 // left
int arr_7_13_right [] = {183, 184, 185, 186};
module line_7_13_right = {LINE_DELAY, 4, arr_7_13_right};      // D-39 -> D-00-31 // right

int arr_13_7_left [] = {187, 188, 189, 190};
module line_13_7_left = {LINE_DELAY, 4, arr_13_7_left};        // D-00-31 -> D-39 // left
int arr_13_7_right [] = {191, 192, 193, 194};
module line_13_7_right = {LINE_DELAY, 4, arr_13_7_right};      // D-00-31 -> D-39 // right

int arr_7_14 [] = {195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220};
module line_7_14 = {LINE_DELAY, 26, arr_7_14};                 // D-39 -> D-66
int arr_14_7 [] = {221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248};
module line_14_7 = {LINE_DELAY, 28, arr_14_7};                 // D-66 -> D-39

int arr_14_8a [] = {249, 250, 251, 252};
module line_14_8a = {LINE_DELAY, 4, arr_14_8a};                // D-66 -> IL3/4(left)
int arr_8a_14 [] = {253, 254, 255, 256};
module line_8a_14 = {LINE_DELAY, 4, arr_8a_14};                // IL3/4(left) -> D-66
int arr_14_8b [] = {257, 258, 259, 260};
module line_14_8b = {LINE_DELAY, 4, arr_14_8b};                // D-66 -> IL3/4(right)
int arr_8b_14 [] = {261, 262, 263, 264};
module line_8b_14 = {LINE_DELAY, 4, arr_8b_14};                // IL3/4(right) -> D-66

int arr_13_9a [] = {265, 266};
module line_13_9a = {LINE_DELAY, 2, arr_13_9a};                // D-00-31 -> IO-3A(left)
int arr_13_9b [] = {267, 268};
module line_13_9b = {LINE_DELAY, 2, arr_13_9b};                // D-00-31 -> IO-3A(right)
int arr_10a_13 [] = {269, 270};
module line_10a_13 = {LINE_DELAY, 2, arr_10a_13};              // IO-3B(left) -> D-00-31
int arr_10b_13 [] = {271, 272};
module line_10b_13 = {LINE_DELAY, 2, arr_10b_13};              // IO-3B(right) -> D-00-31

int arr_13_11a_red [] = {273};
module line_13_11a_red = {LINE_DELAY, 1, arr_13_11a_red};      // D-00-31 -> IT/A(left) red
int arr_13_11a_blue [] = {274};
module line_13_11a_blue = {LINE_DELAY, 1, arr_13_11a_blue};    // D-00-31 -> IT/A(left) blue

int arr_11a_13_red [] = {275};
module line_11a_13_red = {LINE_DELAY, 1, arr_11a_13_red};      // IT/A(left) red -> D-00-31
int arr_11a_13_blue [] = {276};
module line_11a_13_blue = {LINE_DELAY, 1, arr_11a_13_blue};    // IT/A(left) blue -> D-00-31

int arr_13_11b_red [] = {277};
module line_13_11b_red = {LINE_DELAY, 1, arr_13_11b_red};      // D-00-31 -> IT/A(right) red
int arr_13_11b_blue [] = {278};
module line_13_11b_blue = {LINE_DELAY, 1, arr_13_11b_blue};    // D-00-31 -> IT/A(right) blue

int arr_11b_13_red [] = {279};
module line_11b_13_red = {LINE_DELAY, 1, arr_11b_13_red};      // IT/A(right) red -> D-00-31
int arr_11b_13_blue [] = {280};
module line_11b_13_blue = {LINE_DELAY, 1, arr_11b_13_blue};    // IT/A(right) blue -> D-00-31

int arr_13_14_left [] = {281, 282, 283, 284, 285, 286, 287, 288, 289};
module line_13_14_left = {LINE_DELAY, 9, arr_13_14_left};      // D-00-31 -> D-66 // left
int arr_13_14_right [] = {290, 291, 292, 293, 294, 295, 296, 297, 298};
module line_13_14_right = {LINE_DELAY, 9, arr_13_14_right};    // D-00-31 -> D-66 // right

int arr_14_13_left [] = {299, 300, 301, 302, 303, 304, 305, 306, 307};
module line_14_13_left = {LINE_DELAY, 9, arr_14_13_left};      // D-66 -> D-00-31 // left
int arr_14_13_right [] = {308, 309, 310, 311, 312, 313, 314, 315, 316};
module line_14_13_right = {LINE_DELAY, 9, arr_14_13_right};    // D-66 -> D-00-31 // right

int arr_14_RK_left_red [] = {317};
module line_14_RK_left_red = {LINE_DELAY, 1, arr_14_RK_left_red};         // D-66 -> RK(left) // red
int arr_14_RK_right_red [] = {318};
module line_14_RK_right_red = {LINE_DELAY, 1, arr_14_RK_right_red};       // D-66 -> RK(right) // red
int arr_14_RK_left_blue [] = {319};
module line_14_RK_left_blue = {LINE_DELAY, 1, arr_14_RK_left_blue};       // D-66 -> RK(left) // blue
int arr_14_RK_right_blue [] = {320};
module line_14_RK_right_blue = {LINE_DELAY, 1, arr_14_RK_right_blue};     // D-66 -> RK(right) // blue

int arr_RK_14_left_red [] = {321};
module line_RK_14_left_red = {LINE_DELAY, 1, arr_RK_14_left_red};         // RK(left) -> D-66 // red
int arr_RK_14_right_red [] = {322};
module line_RK_14_right_red = {LINE_DELAY, 1, arr_RK_14_right_red};       // RK(right) -> D-66 // red
int arr_RK_14_left_blue [] = {323};
module line_RK_14_left_blue = {LINE_DELAY, 1, arr_RK_14_left_blue};       // RK(left) -> D-66 // blue
int arr_RK_14_right_blue [] = {324};
module line_RK_14_right_blue = {LINE_DELAY, 1, arr_RK_14_right_blue};     // RK(right) -> D-66 // blue

int arr_14_P_296_left_red [] = {325};
module line_14_P_296_left_red = {LINE_DELAY, 1, arr_14_RK_left_red};      // D-66 -> P-296(left) // red
int arr_14_P_296_right_red [] = {326};
module line_14_P_296_right_red = {LINE_DELAY, 1, arr_14_RK_right_red};    // D-66 -> P-296(right) // red
int arr_14_P_296_left_blue [] = {327};
module line_14_P_296_left_blue = {LINE_DELAY, 1, arr_14_RK_left_blue};    // D-66 -> P-296(left) // blue
int arr_14_P_296_right_blue [] = {328};
module line_14_P_296_right_blue = {LINE_DELAY, 1, arr_14_RK_right_blue};  // D-66 -> P-296(right) // blue

int arr_14_PTRK_10x2_left_red [] = {329, 330, 331};
module line_14_PTRK_10x2_left_red = {LINE_DELAY, 3, arr_14_PTRK_10x2_left_red};      // D-66 -> PTRK 10x2(left) // red
int arr_14_PTRK_10x2_right_red [] = {332, 333, 334};
module line_14_PTRK_10x2_right_red = {LINE_DELAY, 3, arr_14_PTRK_10x2_right_red};    // D-66 -> PTRK 10x2(right) // red
int arr_14_PTRK_10x2_left_blue [] = {335, 336, 337};
module line_14_PTRK_10x2_left_blue = {LINE_DELAY, 3, arr_14_PTRK_10x2_left_blue};    // D-66 -> PTRK 10x2(left) // blue
int arr_14_PTRK_10x2_right_blue [] = {338, 339, 340};
module line_14_PTRK_10x2_right_blue = {LINE_DELAY, 3, arr_14_PTRK_10x2_right_blue};  // D-66 -> PTRK 10x2(right) // blue


//////////////////////// modes ////////////////////////

int arr_mode_1 [] = {341};
module mode_1 = {LINE_DELAY, 1, arr_mode_1};
int arr_mode_2 [] = {342};
module mode_2 = {LINE_DELAY, 1, arr_mode_2};
int arr_mode_3 [] = {343};
module mode_3 = {LINE_DELAY, 1, arr_mode_3};
int arr_mode_4 [] = {344};
module mode_4 = {LINE_DELAY, 1, arr_mode_4};
int arr_mode_5 [] = {345};
module mode_5 = {LINE_DELAY, 1, arr_mode_5};
int arr_mode_6 [] = {346};
module mode_6 = {LINE_DELAY, 1, arr_mode_6};
int arr_mode_7 [] = {347};
module mode_7 = {LINE_DELAY, 1, arr_mode_7};
int arr_mode_8 [] = {348};
module mode_8 = {LINE_DELAY, 1, arr_mode_8};
int arr_mode_9 [] = {349};
module mode_9 = {LINE_DELAY, 1, arr_mode_9};
int arr_mode_10 [] = {350};
module mode_10 = {LINE_DELAY, 1, arr_mode_10};
int arr_mode_11 [] = {351};
module mode_11 = {LINE_DELAY, 1, arr_mode_11};
int arr_mode_12 [] = {352};
module mode_12 = {LINE_DELAY, 1, arr_mode_12};
int arr_mode_13 [] = {353};
module mode_13 = {LINE_DELAY, 1, arr_mode_13};
int arr_mode_14 [] = {354};
module mode_14 = {LINE_DELAY, 1, arr_mode_14};
int arr_mode_15 [] = {355};
module mode_15 = {LINE_DELAY, 1, arr_mode_15};
int arr_mode_16 [] = {356};
module mode_16 = {LINE_DELAY, 1, arr_mode_16};
int arr_mode_17 [] = {357};
module mode_17 = {LINE_DELAY, 1, arr_mode_17};
int arr_mode_18 [] = {358};
module mode_18 = {LINE_DELAY, 1, arr_mode_18};
int arr_mode_19 [] = {359};
module mode_19 = {LINE_DELAY, 1, arr_mode_19};
int arr_mode_20 [] = {360};
module mode_20 = {LINE_DELAY, 1, arr_mode_20};
int arr_mode_21 [] = {361};
module mode_21 = {LINE_DELAY, 1, arr_mode_21};

#endif
