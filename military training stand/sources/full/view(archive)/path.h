#ifndef _PATH_
#define _PATH_

#include "modules.h"

typedef struct pathStruct {
  int count;
  module** moduleArray;
} path;

// in - from antenn to connector
// out - from connector to antenn

module* path1_arr_in [28] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7_left, &line_6_7_right, &block_7_D_39, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_7_13_left, &line_7_13_right, &line_11a_13_red, &line_11b_13_red, &block_13_D_00_31, &line_13_14_left, &line_13_14_right, &block_14_D_66, &line_14_PTRK_10x2_left_red, &line_14_PTRK_10x2_right_red};
path path1_in = {28, path1_arr_in};
module* path1_arr_out [28] = {&line_14_PTRK_10x2_left_blue, &line_14_PTRK_10x2_right_blue, &block_14_D_66, &line_14_13_left, &line_14_13_right, &block_13_D_00_31, &line_13_11a_blue, &line_13_11b_blue, &line_13_7_left, &line_13_7_right, &block_11a_IT_A_left, &block_11b_IT_A_right, &block_7_D_39, &line_7_6_left, &line_7_6_right, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path1_out = {28, path1_arr_out};

module* path2_arr_in [36] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7_left, &line_6_7_right, &block_7_D_39, &line_7_8a, &line_7_8b, &line_7_10a, &line_7_10b, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &block_10a_IO_3B_left, &block_10b_IO_3B_right, &line_10a_13, &line_10b_13, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_11a_13_red, &line_11b_13_red, &block_13_D_00_31, &line_8a_14, &line_8b_14, &line_13_14_left, &line_13_14_right, &block_14_D_66};
path path2_in = {36, path2_arr_in};
module* path2_arr_out [40] = {&line_14_PTRK_10x2_left_blue, &line_14_PTRK_10x2_right_blue, &line_14_P_296_left_blue, &line_14_P_296_right_blue, &block_14_D_66, &line_14_13_left, &line_14_13_right, &line_14_8a, &line_14_8b, &block_13_D_00_31, &line_13_11a_blue, &line_13_11b_blue, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_13_9a, &line_13_9b, &block_9a_IO_3A_left, &block_9b_IO_3A_right, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_9a_7, &line_9b_7, &line_8a_7, &line_8b_7, &block_7_D_39, &line_7_6_left, &line_7_6_right, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path2_out = {40, path2_arr_out};

module* path3_arr_in [40] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7_left, &line_6_7_right, &block_7_D_39, &line_7_8a, &line_7_8b, &line_7_10a, &line_7_10b, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &block_10a_IO_3B_left, &block_10b_IO_3B_right, &line_10a_13, &line_10b_13, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_11a_13_red, &line_11b_13_red, &block_13_D_00_31, &line_8a_14, &line_8b_14, &line_13_14_left, &line_13_14_right, &block_14_D_66, &line_14_P_296_left_red, &line_14_P_296_right_red, &line_14_PTRK_10x2_left_red, &line_14_PTRK_10x2_right_red};
path path3_in = {40, path3_arr_in};
module* path3_arr_out [40] = {&line_14_PTRK_10x2_left_blue, &line_14_PTRK_10x2_right_blue, &line_14_P_296_left_blue, &line_14_P_296_right_blue, &block_14_D_66, &line_14_13_left, &line_14_13_right, &line_14_8a, &line_14_8b, &block_13_D_00_31, &line_13_11a_blue, &line_13_11b_blue, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_13_9a, &line_13_9b, &block_9a_IO_3A_left, &block_9b_IO_3A_right, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_9a_7, &line_9b_7, &line_8a_7, &line_8b_7, &block_7_D_39, &line_7_6_left, &line_7_6_right, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path3_out = {40, path3_arr_out};

module* path4_arr_in [42] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7_left, &line_6_7_right, &block_12_IO_4, &line_12_7, &block_7_D_39, &line_7_8a, &line_7_8b, &line_7_10a, &line_7_10b, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &block_10a_IO_3B_left, &block_10b_IO_3B_right, &line_10a_13, &line_10b_13, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_11a_13_red, &line_11b_13_red, &block_13_D_00_31, &line_8a_14, &line_8b_14, &line_13_14_left, &line_13_14_right, &block_14_D_66, &line_14_P_296_left_red, &line_14_P_296_right_red, &line_14_PTRK_10x2_left_red, &line_14_PTRK_10x2_right_red};
path path4_in = {42, path4_arr_in};
module* path4_arr_out [42] = {&line_14_PTRK_10x2_left_blue, &line_14_PTRK_10x2_right_blue, &line_14_P_296_left_blue, &line_14_P_296_right_blue, &block_14_D_66, &line_14_13_left, &line_14_13_right, &line_14_8a, &line_14_8b, &block_13_D_00_31, &line_13_11a_blue, &line_13_11b_blue, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_13_9a, &line_13_9b, &block_9a_IO_3A_left, &block_9b_IO_3A_right, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_9a_7, &line_9b_7, &line_8a_7, &line_8b_7, &block_7_D_39, &line_7_12, &block_12_IO_4, &line_7_6_left, &line_7_6_right, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path4_out = {42, path4_arr_out};

module* path5_8_arr_in [21] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7_left, &line_6_7_right, &block_7_D_39, &line_7_14_left, &line_7_14_right, &block_14_D_66, &line_14_RK_left_red, &line_14_RK_right_red};
path path5_8_in = {21, path5_8_arr_in};
module* path5_8_arr_out [21] = {&line_RK_14_left_blue, &line_RK_14_right_blue, &block_14_D_66, &line_14_7_left, &line_14_7_right, &block_7_D_39, &line_7_6_left, &line_7_6_right, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path5_8_out = {21, path5_8_arr_out};

module* path9_arr_in [13] = {&line_14_PTRK_10x2_right_red, &line_RK_14_right_red, &block_14_D_66, &line_14_13_right, &line_14_7_right, &block_7_D_39, &line_7_10b, &block_10b_IO_3B_right, &line_10b_13, &block_13_D_00_31, &line_13_11b_red, &block_11b_IT_A_right, &line_11b_13_red};
path path9_in = {13, path9_arr_in};
module* path9_arr_out [26] = {&block_13_D_00_31, &line_13_11a_blue, &block_11a_IT_A_left, &line_11a_13_blue, &line_13_14_left, &block_14_D_66, &line_14_PTRK_10x2_left_blue, &line_13_9a, &block_9a_IO_3A_left, &line_9a_7, &block_7_D_39, &line_7_6_left, &line_7_6_right, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path9_out = {26, path9_arr_out};

module* path10_arr_in [26] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7_left, &line_6_7_right, &block_7_D_39, &line_7_10a, &block_10a_IO_3B_left, &line_10a_13, &block_13_D_00_31, &line_13_11a_red, &block_11a_IT_A_left, &line_11a_13_red, &line_13_14_left, &block_14_D_66, &line_14_PTRK_10x2_left_red};
path path10_in = {26, path10_arr_in};
module* path10_arr_out [13] = {&line_14_PTRK_10x2_right_blue, &line_RK_14_right_blue, &block_14_D_66, &line_14_13_right, &block_13_D_00_31, &line_14_7_right, &block_7_D_39, &line_13_11b_blue, &block_11b_IT_A_right, &line_11b_13_blue, &line_13_9b, &block_9b_IO_3A_right, &line_9b_7};
path path10_out = {13, path10_arr_out};

module* path11_arr_in [16] = {&line_RK_14_right_red, &line_14_P_296_right_red, &block_14_D_66, &line_14_13_right, &line_14_8b, &line_14_7_right, &block_8b_IL3_4_right, &line_8b_7, &block_7_D_39, &line_7_10b, &block_10b_IO_3B_right, &line_10b_13, &block_13_D_00_31, &line_13_11b_red, &block_11b_IT_A_right, &line_11b_13_red};
path path11_in = {16, path11_arr_in};
module* path11_arr_out [30] = {&block_13_D_00_31, &line_13_11a_blue, &block_11a_IT_A_left, &line_11a_13_blue, &line_13_14_left, &block_14_D_66, &line_14_PTRK_10x2_left_blue, &line_14_P_296_left_blue, &line_13_9a, &block_9a_IO_3A_left, &line_9a_7, &block_7_D_39, &line_7_8a, &block_8a_IL3_4_left, &line_8a_14, &line_7_6_left, &line_7_6_right, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path11_out = {30, path11_arr_out};

module* path12_arr_in [30] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7_left, &line_6_7_right, &block_7_D_39, &line_7_8a, &line_7_10a, &block_8a_IL3_4_left, &block_10a_IO_3B_left, &line_10a_13, &block_13_D_00_31, &line_13_11a_red, &block_11a_IT_A_left, &line_11a_13_red, &line_8a_14, &line_13_14_left, &block_14_D_66, &line_14_PTRK_10x2_left_red, &line_14_P_296_left_red};
path path12_in = {30, path12_arr_in};
module* path12_arr_out [16] = {&line_14_PTRK_10x2_right_blue, &line_14_P_296_right_blue, &line_RK_14_right_blue, &block_14_D_66, &line_14_13_right, &block_13_D_00_31, &line_13_11b_blue, &block_11b_IT_A_right, &line_11b_13_blue, &line_13_9b, &line_14_8b, &block_8b_IL3_4_right, &block_9b_IO_3A_right, &line_9b_7, &line_8b_7, &block_7_D_39};
path path12_out = {16, path12_arr_out};

module* path13_arr_out [42] = {&line_14_PTRK_10x2_left_blue, &line_14_PTRK_10x2_right_blue, &line_14_P_296_left_blue, &line_14_P_296_right_blue, &line_RK_14_left_blue, &line_RK_14_right_blue, &block_14_D_66, &line_14_13_left, &line_14_13_right, &block_13_D_00_31, &line_14_8a, &line_14_8b, &line_13_9a, &line_13_9b, &block_9a_IO_3A_left, &block_9b_IO_3A_right, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_8a_7, &line_8b_7, &line_9a_7, &line_9b_7, &line_14_7_left, &line_14_7_right, &block_7_D_39, &line_7_12, &block_12_IO_4, &line_7_6_left, &line_7_6_right, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path13_out = {42, path13_arr_out};

module* path14_arr_in [48] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7_left, &line_6_7_right, &block_7_D_39, &block_12_IO_4, &line_12_7, &line_7_8a, &line_7_8b, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_7_10a, &line_7_10b, &block_10a_IO_3B_left, &block_10b_IO_3B_right, &line_10a_13, &line_10b_13, &block_13_D_00_31, &line_13_11a_red, &line_13_11b_red, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_11a_13_red, &line_11b_13_red, &line_7_14_left, &line_7_14_right, &line_8a_14, &line_8b_14, &line_13_14_left, &line_13_14_right, &block_14_D_66, &line_14_PTRK_10x2_left_red, &line_14_PTRK_10x2_right_red, &line_14_P_296_left_red, &line_14_P_296_right_red, &line_RK_14_left_red, &line_RK_14_right_red};
path path14_in = {48, path14_arr_in};

module* path15_arr_in [16] = {&block_1_D_00_39, &line_1_4a, &block_4a_MSHU_left, &line_4a_5a, &block_5a_D_55M_left, &line_5a_6, &block_6_D_38A, &line_6_7_left, &block_7_D_39, &line_7_13_left, &block_13_D_00_31, &line_13_11a_red, &block_11a_IT_A_left, &line_13_14_left, &block_14_D_66, &line_14_PTRK_10x2_left_red};
path path15_in = {16, path15_arr_in};
module* path15_arr_out [16] = {&line_14_PTRK_10x2_left_blue, &block_14_D_66, &line_14_13_left, &block_13_D_00_31, &block_11a_IT_A_left, &line_11a_13_blue, &line_13_7_left, &block_7_D_39, &line_7_6_left, &block_6_D_38A, &line_6_5a, &block_5a_D_55M_left, &line_5a_3a, &block_3a_D_53B_left, &line_3a_1, &block_1_D_00_39};
path path15_out = {16, path15_arr_out};

module* path16_19_arr_in [16] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7_left, &line_6_7_right, &block_7_D_39};
path path16_19_in = {16, path16_19_arr_in};
module* path16_19_arr_out [16] = {&block_7_D_39, &line_7_6_left, &line_7_6_right, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path16_19_out = {16, path16_19_arr_out};

module* path20_21_arr_in [24] = {&block_1_D_00_39, &line_1_4a, &block_4a_MSHU_left, &line_4a_5a, &block_5a_D_55M_left, &line_5a_6, &block_6_D_38A, &line_6_7_left, &line_6_7_right, &block_7_D_39, &line_7_8a, &line_7_10a, &block_8a_IL3_4_left, &block_10a_IO_3B_left, &line_10a_13, &block_13_D_00_31, &line_13_11a_red, &block_11a_IT_A_left, &line_11a_13_red, &line_8a_14, &line_13_14_left, &block_14_D_66, &line_14_PTRK_10x2_left_red, &line_14_P_296_left_red};
path path20_21_in = {24, path20_21_arr_in};
module* path20_21_arr_out [24] = {&line_14_PTRK_10x2_right_blue, &line_14_P_296_right_blue, &block_14_D_66, &line_14_13_right, &block_13_D_00_31, &line_13_11b_blue, &block_11b_IT_A_right, &line_11b_13_blue, &line_13_9b, &line_14_8b, &block_8b_IL3_4_right, &block_9b_IO_3A_right, &line_9b_7, &line_8b_7, &block_7_D_39, &line_7_6_left, &line_7_6_right, &block_6_D_38A, &line_6_5b, &block_5b_D_55M_right, &line_5b_3b, &block_3b_D_53B_right, &line_3b_2, &block_2_D_00_40};
path path20_21_out = {24, path20_21_arr_out};

module* mode_arr [21] = {&mode_1, &mode_2, &mode_3, &mode_4, &mode_5, &mode_6, &mode_7, &mode_8, &mode_9, &mode_10, &mode_11, &mode_12, &mode_13, &mode_14, &mode_15, &mode_16, &mode_17, &mode_18, &mode_19, &mode_20, &mode_21};

#endif
