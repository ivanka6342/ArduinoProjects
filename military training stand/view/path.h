#ifndef _PATH_
#define _PATH_

#include "dot_index.h"
#include "modules.h"

#include <MaxMatrix.h>

typedef struct pathStruct {
  int count;
  module** moduleArray;
} path;

// in - from antenn to connector
// out - from connector to antenn

module* path1_arr_in [24] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7, &block_7_D_39, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_7_13, &line_11a_13, &line_11b_13, &block_13_D_00_31, &line_13_14, &block_14_D_66, &line_14_PTRK_10x2};
path path1_in = {24, path1_arr_in};
module* path1_arr_out [24] = {&line_PTRK_10x2_14, &block_14_D_66, &line_14_13, &block_13_D_00_31, &line_13_11a, &line_13_11b, &line_13_7, &block_11a_IT_A_left, &block_11b_IT_A_right, &block_7_D_39, &line_7_6, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path1_out = {24, path1_arr_out};

module* path2_arr_in [34] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7, &block_7_D_39, &line_7_8a, &line_7_8b, &line_7_10a, &line_7_10b, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &block_10a_IO_3B_left, &block_10b_IO_3B_right, &line_10a_13, &line_10b_13, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_11a_13, &line_11b_13, &block_13_D_00_31, &line_8a_14, &line_8b_14, &line_13_14, &block_14_D_66};
path path2_in = {34, path2_arr_in};
module* path2_arr_out [36] = {&line_PTRK_10x2_14, &line_P_296_14, &block_14_D_66, &line_14_13, &line_14_8a, &line_14_8b, &block_13_D_00_31, &line_13_11a, &line_13_11b, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_13_9a, &line_13_9b, &block_9a_IO_3A_left, &block_9b_IO_3A_right, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_9a_7, &line_9b_7, &line_8a_7, &line_8b_7, &block_7_D_39, &line_7_6, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path2_out = {36, path2_arr_out};

module* path3_arr_in [36] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7, &block_7_D_39, &line_7_8a, &line_7_8b, &line_7_10a, &line_7_10b, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &block_10a_IO_3B_left, &block_10b_IO_3B_right, &line_10a_13, &line_10b_13, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_11a_13, &line_11b_13, &block_13_D_00_31, &line_8a_14, &line_8b_14, &line_13_14, &block_14_D_66, &line_14_P_296, &line_14_PTRK_10x2};
path path3_in = {36, path3_arr_in};
module* path3_arr_out [36] = {&line_PTRK_10x2_14, &line_P_296_14, &block_14_D_66, &line_14_13, &line_14_8a, &line_14_8b, &block_13_D_00_31, &line_13_11a, &line_13_11b, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_13_9a, &line_13_9b, &block_9a_IO_3A_left, &block_9b_IO_3A_right, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_9a_7, &line_9b_7, &line_8a_7, &line_8b_7, &block_7_D_39, &line_7_6, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path3_out = {36, path3_arr_out};

module* path4_arr_in [38] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7, &block_12_IO_4, &line_12_7, &block_7_D_39, &line_7_8a, &line_7_8b, &line_7_10a, &line_7_10b, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &block_10a_IO_3B_left, &block_10b_IO_3B_right, &line_10a_13, &line_10b_13, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_11a_13, &line_11b_13, &block_13_D_00_31, &line_8a_14, &line_8b_14, &line_13_14, &block_14_D_66, &line_14_P_296, &line_14_PTRK_10x2};
path path4_in = {38, path4_arr_in};
module* path4_arr_out [38] = {&line_PTRK_10x2_14, &line_P_296_14, &block_14_D_66, &line_14_13, &line_14_8a, &line_14_8b, &block_13_D_00_31, &line_13_11a, &line_13_11b, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_13_9a, &line_13_9b, &block_9a_IO_3A_left, &block_9b_IO_3A_right, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_9a_7, &line_9b_7, &line_8a_7, &line_8b_7, &block_7_D_39, &line_7_12, &block_12_IO_4, &line_7_6, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path4_out = {38, path4_arr_out};

module* path5_8_arr_in [18] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7, &block_7_D_39, &line_7_14, &block_14_D_66, &line_14_RK};
path path5_8_in = {18, path5_8_arr_in};
module* path5_8_arr_out [18] = {&line_RK_14, &block_14_D_66, &line_14_7, &block_7_D_39, &line_7_6, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path5_8_out = {18, path5_8_arr_out};

/*
module* path9_arr_in [36] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7, &block_7_D_39, &line_7_8a, &line_7_8b, &line_7_10a, &line_7_10b, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &block_10a_IO_3B_left, &block_10b_IO_3B_right, &line_10a_13, &line_10b_13, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_11a_13, &line_11b_13, &block_13_D_00_31, &line_8a_14, &line_8b_14, &line_13_14, &block_14_D_66, &line_14_P_296, &line_14_PTRK_10x2};
path path9_in = {36, path9_arr_in};
module* path9_arr_out [36] = {&line_PTRK_10x2_14, &line_P_296_14, &block_14_D_66, &line_14_13, &line_14_8a, &line_14_8b, &block_13_D_00_31, &line_13_11a, &line_13_11b, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_13_9a, &line_13_9b, &block_9a_IO_3A_left, &block_9b_IO_3A_right, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_9a_7, &line_9b_7, &line_8a_7, &line_8b_7, &block_7_D_39, &line_7_6, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path9_out = {36, path9_arr_out};
*/

// is it need D-66 -> D-39 connection
// out-part ends with D-39 or not?
// only left and right part works or i can unite it?
// where the place of the IT/A in path? what is it destination and doubling?
module* path10_arr_in [29] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7, &block_7_D_39, &line_7_10a, &line_7_10b, &block_10a_IO_3B_left, &block_10b_IO_3B_right, &line_10a_13, &line_10b_13, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_11a_13, &line_11b_13, &block_13_D_00_31, &line_13_14, &block_14_D_66, &line_14_PTRK_10x2};
path path10_in = {29, path10_arr_in};
module* path10_arr_out [29] = {&line_PTRK_10x2_14, &block_14_D_66, &line_14_13, &block_13_D_00_31, &line_13_11a, &line_13_11b, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_13_9a, &line_13_9b, &block_9a_IO_3A_left, &block_9b_IO_3A_right, &line_9a_7, &line_9b_7, &block_7_D_39, &line_7_6, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path10_out = {29, path10_arr_out};

// wtf D-00-31 <-> D-66 and D-38A <-> D-39 connections
module* path11_arr_in [] = {};
path path11_in = {1, path11_arr_in};
module* path11_arr_out [] = {};
path path11_out = {1, path11_arr_out};

// wtf D-39 -> D-66 out(blue) connection?
module* path12_arr_in [] = {};
path path12_in = {1, path12_arr_in};
module* path12_arr_out [] = {};
path path12_out = {1, path12_arr_out};

// why not using IT/A like path14 ?
module* path13_arr_out [36] = {&line_PTRK_10x2_14, &line_P_296_14, &line_RK_14, &block_14_D_66, &line_14_13, &block_13_D_00_31, &line_14_8a, &line_14_8b, &line_13_9a, &line_13_9b, &block_9a_IO_3A_left, &block_9b_IO_3A_right, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_8a_7, &line_8b_7, &line_9a_7, &line_9b_7, &line_14_7, &block_7_D_39, &line_7_12, &block_12_IO_4, &line_7_6, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path13_out = {36, path13_arr_out};

module* path14_arr_in [40] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7, &block_7_D_39, &line_7_12, &block_12_IO_4, &line_7_8a, &line_7_8b, &block_8a_IL3_4_left, &block_8b_IL3_4_right, &line_7_10a, &line_7_10b, &block_10a_IO_3B_left, &block_10b_IO_3B_right, &line_10a_13, &line_10b_13, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_11a_13, &line_11b_13, &block_13_D_00_31, &line_7_14, &line_8a_14, &line_8b_14, &line_13_14, &block_14_D_66, &line_14_PTRK_10x2, &line_14_P_296, &line_14_RK};
path path14_in = {40, path14_arr_in};

module* path15_arr_in [24] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7, &block_7_D_39, &line_7_13, &line_13_11a, &line_13_11b, &block_11a_IT_A_left, &block_11b_IT_A_right, &block_13_D_00_31, &line_13_14, &block_14_D_66, &line_14_PTRK_10x2};
path path15_in = {24, path15_arr_in};
module* path15_arr_out [24] = {&line_PTRK_10x2_14, &block_14_D_66, &line_14_13, &block_13_D_00_31, &line_13_11a, &line_13_11b, &block_11a_IT_A_left, &block_11b_IT_A_right, &line_13_7, &block_7_D_39, &line_7_6, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path15_out = {24, path15_arr_out};

// is the D-39 used?
module* path16_19_arr_in [15] = {&block_1_D_00_39, &block_2_D_00_40, &line_1_4a, &line_2_4b, &block_4a_MSHU_left, &block_4b_MSHU_right, &line_4a_5a, &line_4b_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_6, &line_5b_6, &block_6_D_38A, &line_6_7, &block_7_D_39};
path path16_19_in = {15, path16_19_arr_in};
module* path16_19_arr_out [15] = {&block_7_D_39, &line_7_6, &block_6_D_38A, &line_6_5a, &line_6_5b, &block_5a_D_55M_left, &block_5b_D_55M_right, &line_5a_3a, &line_5b_3b, &block_3a_D_53B_left, &block_3b_D_53B_right, &line_3a_1, &line_3b_2, &block_1_D_00_39, &block_2_D_00_40};
path path16_19_out = {15, path16_19_arr_out};

module* path20_21_arr_in [] = {};
path path20_21_in = {1, path20_21_arr_in};
module* path20_21_arr_out [] = {};
path path20_21_out = {1, path20_21_arr_out};

#endif
