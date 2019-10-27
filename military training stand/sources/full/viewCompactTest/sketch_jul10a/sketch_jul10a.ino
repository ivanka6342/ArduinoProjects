#include <MaxMatrix.h>
#include <avr/wdt.h>

#define DIN 12
#define LOAD 10
#define CLK 11
#define M_COUNT 6
#define N_MATRIX 5 

//LedControl matrix(DIN, CLK, LOAD, M_COUNT);
MaxMatrix matrix(DIN, LOAD, CLK, M_COUNT);


void setup() {  
  matrix.init();
  matrix.setIntensity(7);
  matrix.clear();
  //ewdt_enable(WDTO_2S);
//  TURN ON ALL MATRIX 
//  for (int i=8*(M_COUNT-(N_MATRIX)); i<8*(M_COUNT-(N_MATRIX-1)); i++) {
//     for (int j=0; j<8; j++) {
//        matrix.setDot(i,j,1);
//     }
//  }

//  TURN ON ALL
  for (int i=0; i<8*M_COUNT; i++) {
     for (int j=0; j<8; j++) {
        matrix.setDot(i,j,1);
     }
  }
//   for (int n=0; n<matrix.getDeviceCount(); n++) {
//      matrix.shutdown(n, false);
//      matrix.setIntensity(n, 7);
//      matrix.clearDisplay(n);
//   }
//
//   for (int n=0; n<matrix.getDeviceCount(); n++)
//    matrix.clearDisplay(n);
//
//  for (int n=0; n<matrix.getDeviceCount(); n++) {
//      for (int i=0; i<8; i++) {
//        for (int j=0; j<8; j++) {
//        //matrix.setRow(N_MATRIX, i, 1);
//        //matrix.setColumn(N_MATRIX, j, 1);
//          //delay(100);
//          matrix.setLed(n, i, j, true);
//          //delay(100);
//          //matrix.setLed(n, i, j, false);
//        }
//      }
//    }
}

void loop() {
  //wdt_reset();
// ONE MATRIX ONE BY ONE LIGHT
  //matrix.clear();
  //for (int i=8*(M_COUNT-(N_MATRIX)); i<8*(M_COUNT-(N_MATRIX-1)); i++) {
  
  

//  ////////////////////////////////////////////////////////////////////////////////
//  for (int i=0; i<8; i++) {
//     for (int j=0; j<8; j++) {
//        //matrix.setRow(N_MATRIX, i, 1);
//        //matrix.setColumn(N_MATRIX, j, 1);
//        matrix.setLed(N_MATRIX, i, j, 1);
//        //matrix.setDot(i,j,1);
//        delay(100);
//     }
//  }
//  delay(1000);
//  matrix.clearDisplay(N_MATRIX);
  //////////////////////////////////////////////////////////////////////////////////


  
//  LIGHT ONE BY ONE
//  matrix.clear();
//  for (int i=0; i<8*M_COUNT; i++) {
//     for (int j=0; j<8; j++) {
//        matrix.setDot(i,j,1);
//        delay(10);
//     }
//  }
//  delay(1000);

// MATRIX QUERY ONE BY ONE
//  for (int NM=1; NM<=M_COUNT; NM++) {
//  matrix.clear();
//  for (int i=8*(M_COUNT-(NM)); i<8*(M_COUNT-(NM-1)); i++) {
//     for (int j=0; j<8; j++) {
//        matrix.setDot(i,j,1);
//     }
//  }
//  delay(1000);
//}  
//delay(1000);

// ONE MATRIX LIGHT ONE BY ONE
//  matrix.clear();
//  for (int i=8*(M_COUNT-(N_MATRIX)); i<8*(M_COUNT-(N_MATRIX-1)); i++) {
//     for (int j=0; j<8; j++) {
//        matrix.setDot(i,j,1);
//        //delay(10);
//     }
//  }
//  delay(1000);

//  ON/OFF LIGHT 1 MATRIX ONE BY ONE
//  for (int i=0; i<8; i++)
//    for (int j=0; j<8; j++){
//      matrix.setDot(i,j,1);
//      delay(300);
//      matrix.setDot(i,j,0);
//      delay(100);
//    }  
}
