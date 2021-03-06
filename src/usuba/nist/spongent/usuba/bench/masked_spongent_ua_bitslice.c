/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba.
   From the file "nist/spongent/usuba/ua/spongent.ua" (included below). */

#include <stdint.h>

/* Do NOT change the order of those define/include */

#ifndef BITS_PER_REG
#define BITS_PER_REG 32
#endif
/* including the architecture specific .h */
#include "MASKED_UA.h"

/* auxiliary functions */
void sBox__B1 (/*inputs*/ DATATYPE x0__[MASKING_ORDER],DATATYPE x1__[MASKING_ORDER],DATATYPE x2__[MASKING_ORDER],DATATYPE x3__[MASKING_ORDER], /*outputs*/ DATATYPE y0__[MASKING_ORDER],DATATYPE y1__[MASKING_ORDER],DATATYPE y2__[MASKING_ORDER],DATATYPE y3__[MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp10_[MASKING_ORDER];
  DATATYPE _tmp14_[MASKING_ORDER];
  DATATYPE _tmp15_;
  DATATYPE _tmp16_;
  DATATYPE _tmp17_[MASKING_ORDER];
  DATATYPE _tmp18_[MASKING_ORDER];
  DATATYPE _tmp19_;
  DATATYPE _tmp2_[MASKING_ORDER];
  DATATYPE _tmp3_;
  DATATYPE _tmp4_;
  DATATYPE _tmp7_[MASKING_ORDER];
  DATATYPE _tmp8_;
  DATATYPE q[8][MASKING_ORDER];
  DATATYPE t[4][MASKING_ORDER];

  // Instructions (body)
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    q[0][_mask_idx] = XOR(x0__[_mask_idx],x2__[_mask_idx]);
    q[1][_mask_idx] = XOR(x1__[_mask_idx],x2__[_mask_idx]);
    _tmp16_ = XOR(x0__[_mask_idx],x1__[_mask_idx]);
    _tmp17_[_mask_idx] = XOR(_tmp16_,x2__[_mask_idx]);
    _tmp18_[_mask_idx] = XOR(x0__[_mask_idx],x3__[_mask_idx]);
  }
  MASKED_AND(t[0],q[0],q[1]);
  _tmp2_[0] = NOT(x0__[0]);
  for (int _mask_idx = 1; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    _tmp2_[_mask_idx] = x0__[_mask_idx];
    _tmp10_[_mask_idx] = x1__[_mask_idx];
  }
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    _tmp3_ = XOR(_tmp2_[_mask_idx],x1__[_mask_idx]);
    _tmp4_ = XOR(_tmp3_,x3__[_mask_idx]);
    q[2][_mask_idx] = XOR(_tmp4_,t[0][_mask_idx]);
  }
  MASKED_AND(t[1],q[2],_tmp2_);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    q[4][_mask_idx] = XOR(x1__[_mask_idx],t[1][_mask_idx]);
    _tmp7_[_mask_idx] = XOR(q[1][_mask_idx],x3__[_mask_idx]);
    _tmp8_ = XOR(_tmp7_[_mask_idx],t[0][_mask_idx]);
    q[5][_mask_idx] = XOR(_tmp8_,t[1][_mask_idx]);
  }
  MASKED_AND(t[2],q[4],q[5]);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    q[6][_mask_idx] = XOR(x2__[_mask_idx],t[0][_mask_idx]);
  }
  _tmp10_[0] = NOT(x1__[0]);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    q[7][_mask_idx] = XOR(_tmp10_[_mask_idx],t[0][_mask_idx]);
    _tmp14_[_mask_idx] = XOR(q[0][_mask_idx],x3__[_mask_idx]);
  }
  MASKED_AND(t[3],q[6],q[7]);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    y0__[_mask_idx] = XOR(_tmp7_[_mask_idx],t[2][_mask_idx]);
    _tmp15_ = XOR(_tmp14_[_mask_idx],t[0][_mask_idx]);
    y1__[_mask_idx] = XOR(_tmp15_,t[1][_mask_idx]);
    y2__[_mask_idx] = XOR(_tmp17_[_mask_idx],t[1][_mask_idx]);
    _tmp19_ = XOR(_tmp18_[_mask_idx],t[0][_mask_idx]);
    y3__[_mask_idx] = XOR(_tmp19_,t[3][_mask_idx]);
  }

}

void sBoxLayer__B1 (/*inputs*/ DATATYPE state__[20][8][MASKING_ORDER], /*outputs*/ DATATYPE stateR__[20][8][MASKING_ORDER]) {

  // Variables declaration
  ;

  // Instructions (body)
  for (int i__ = 0; i__ <= 19; i__++) {
    sBox__B1(state__[i__][0],state__[i__][1],state__[i__][2],state__[i__][3],stateR__[i__][0],stateR__[i__][1],stateR__[i__][2],stateR__[i__][3]);
    sBox__B1(state__[i__][4],state__[i__][5],state__[i__][6],state__[i__][7],stateR__[i__][4],stateR__[i__][5],stateR__[i__][6],stateR__[i__][7]);
  }

}

void pLayer__B1 (/*inputs*/ DATATYPE state__[20][8][MASKING_ORDER], /*outputs*/ DATATYPE stateR__[20][8][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE x__[MASKING_ORDER];

  // Instructions (body)
  for (int i__ = 0; i__ <= 18; i__++) {
    for (int j__ = 0; j__ <= 7; j__++) {
      for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
        x__[_mask_idx] = state__[i__][(7 - j__)][_mask_idx];
        stateR__[(((((8 * i__) + j__) * 40) % 159) / 8)][(7 - (((((8 * i__) + j__) * 40) % 159) - (8 * (((((8 * i__) + j__) * 40) % 159) / 8))))][_mask_idx] = x__[_mask_idx];
      }
    }
  }
  for (int j__ = 0; j__ <= 6; j__++) {
    for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
      x__[_mask_idx] = state__[19][(7 - j__)][_mask_idx];
      stateR__[((((152 + j__) * 40) % 159) / 8)][(7 - ((((152 + j__) * 40) % 159) - (8 * ((((152 + j__) * 40) % 159) / 8))))][_mask_idx] = x__[_mask_idx];
    }
  }
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    stateR__[19][0][_mask_idx] = state__[19][0][_mask_idx];
  }

}

void counterLayer__B1 (/*inputs*/ DATATYPE state__[20][8][MASKING_ORDER],DATATYPE counter__[8][MASKING_ORDER], /*outputs*/ DATATYPE stateR__[20][8][MASKING_ORDER]) {

  // Variables declaration
  ;

  // Instructions (body)
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    stateR__[1][0][_mask_idx] = state__[1][0][_mask_idx];
    stateR__[1][1][_mask_idx] = state__[1][1][_mask_idx];
    stateR__[1][2][_mask_idx] = state__[1][2][_mask_idx];
    stateR__[1][3][_mask_idx] = state__[1][3][_mask_idx];
    stateR__[1][4][_mask_idx] = state__[1][4][_mask_idx];
    stateR__[1][5][_mask_idx] = state__[1][5][_mask_idx];
    stateR__[1][6][_mask_idx] = state__[1][6][_mask_idx];
    stateR__[1][7][_mask_idx] = state__[1][7][_mask_idx];
    stateR__[2][0][_mask_idx] = state__[2][0][_mask_idx];
    stateR__[2][1][_mask_idx] = state__[2][1][_mask_idx];
    stateR__[2][2][_mask_idx] = state__[2][2][_mask_idx];
    stateR__[2][3][_mask_idx] = state__[2][3][_mask_idx];
    stateR__[2][4][_mask_idx] = state__[2][4][_mask_idx];
    stateR__[2][5][_mask_idx] = state__[2][5][_mask_idx];
    stateR__[2][6][_mask_idx] = state__[2][6][_mask_idx];
    stateR__[2][7][_mask_idx] = state__[2][7][_mask_idx];
    stateR__[3][0][_mask_idx] = state__[3][0][_mask_idx];
    stateR__[3][1][_mask_idx] = state__[3][1][_mask_idx];
    stateR__[3][2][_mask_idx] = state__[3][2][_mask_idx];
    stateR__[3][3][_mask_idx] = state__[3][3][_mask_idx];
    stateR__[3][4][_mask_idx] = state__[3][4][_mask_idx];
    stateR__[3][5][_mask_idx] = state__[3][5][_mask_idx];
    stateR__[3][6][_mask_idx] = state__[3][6][_mask_idx];
    stateR__[3][7][_mask_idx] = state__[3][7][_mask_idx];
    stateR__[4][0][_mask_idx] = state__[4][0][_mask_idx];
    stateR__[4][1][_mask_idx] = state__[4][1][_mask_idx];
    stateR__[4][2][_mask_idx] = state__[4][2][_mask_idx];
    stateR__[4][3][_mask_idx] = state__[4][3][_mask_idx];
    stateR__[4][4][_mask_idx] = state__[4][4][_mask_idx];
    stateR__[4][5][_mask_idx] = state__[4][5][_mask_idx];
    stateR__[4][6][_mask_idx] = state__[4][6][_mask_idx];
    stateR__[4][7][_mask_idx] = state__[4][7][_mask_idx];
    stateR__[5][0][_mask_idx] = state__[5][0][_mask_idx];
    stateR__[5][1][_mask_idx] = state__[5][1][_mask_idx];
    stateR__[5][2][_mask_idx] = state__[5][2][_mask_idx];
    stateR__[5][3][_mask_idx] = state__[5][3][_mask_idx];
    stateR__[5][4][_mask_idx] = state__[5][4][_mask_idx];
    stateR__[5][5][_mask_idx] = state__[5][5][_mask_idx];
    stateR__[5][6][_mask_idx] = state__[5][6][_mask_idx];
    stateR__[5][7][_mask_idx] = state__[5][7][_mask_idx];
    stateR__[6][0][_mask_idx] = state__[6][0][_mask_idx];
    stateR__[6][1][_mask_idx] = state__[6][1][_mask_idx];
    stateR__[6][2][_mask_idx] = state__[6][2][_mask_idx];
    stateR__[6][3][_mask_idx] = state__[6][3][_mask_idx];
    stateR__[6][4][_mask_idx] = state__[6][4][_mask_idx];
    stateR__[6][5][_mask_idx] = state__[6][5][_mask_idx];
    stateR__[6][6][_mask_idx] = state__[6][6][_mask_idx];
    stateR__[6][7][_mask_idx] = state__[6][7][_mask_idx];
    stateR__[7][0][_mask_idx] = state__[7][0][_mask_idx];
    stateR__[7][1][_mask_idx] = state__[7][1][_mask_idx];
    stateR__[7][2][_mask_idx] = state__[7][2][_mask_idx];
    stateR__[7][3][_mask_idx] = state__[7][3][_mask_idx];
    stateR__[7][4][_mask_idx] = state__[7][4][_mask_idx];
    stateR__[7][5][_mask_idx] = state__[7][5][_mask_idx];
    stateR__[7][6][_mask_idx] = state__[7][6][_mask_idx];
    stateR__[7][7][_mask_idx] = state__[7][7][_mask_idx];
    stateR__[8][0][_mask_idx] = state__[8][0][_mask_idx];
    stateR__[8][1][_mask_idx] = state__[8][1][_mask_idx];
    stateR__[8][2][_mask_idx] = state__[8][2][_mask_idx];
    stateR__[8][3][_mask_idx] = state__[8][3][_mask_idx];
    stateR__[8][4][_mask_idx] = state__[8][4][_mask_idx];
    stateR__[8][5][_mask_idx] = state__[8][5][_mask_idx];
    stateR__[8][6][_mask_idx] = state__[8][6][_mask_idx];
    stateR__[8][7][_mask_idx] = state__[8][7][_mask_idx];
    stateR__[9][0][_mask_idx] = state__[9][0][_mask_idx];
    stateR__[9][1][_mask_idx] = state__[9][1][_mask_idx];
    stateR__[9][2][_mask_idx] = state__[9][2][_mask_idx];
    stateR__[9][3][_mask_idx] = state__[9][3][_mask_idx];
    stateR__[9][4][_mask_idx] = state__[9][4][_mask_idx];
    stateR__[9][5][_mask_idx] = state__[9][5][_mask_idx];
    stateR__[9][6][_mask_idx] = state__[9][6][_mask_idx];
    stateR__[9][7][_mask_idx] = state__[9][7][_mask_idx];
    stateR__[10][0][_mask_idx] = state__[10][0][_mask_idx];
    stateR__[10][1][_mask_idx] = state__[10][1][_mask_idx];
    stateR__[10][2][_mask_idx] = state__[10][2][_mask_idx];
    stateR__[10][3][_mask_idx] = state__[10][3][_mask_idx];
    stateR__[10][4][_mask_idx] = state__[10][4][_mask_idx];
    stateR__[10][5][_mask_idx] = state__[10][5][_mask_idx];
    stateR__[10][6][_mask_idx] = state__[10][6][_mask_idx];
    stateR__[10][7][_mask_idx] = state__[10][7][_mask_idx];
    stateR__[11][0][_mask_idx] = state__[11][0][_mask_idx];
    stateR__[11][1][_mask_idx] = state__[11][1][_mask_idx];
    stateR__[11][2][_mask_idx] = state__[11][2][_mask_idx];
    stateR__[11][3][_mask_idx] = state__[11][3][_mask_idx];
    stateR__[11][4][_mask_idx] = state__[11][4][_mask_idx];
    stateR__[11][5][_mask_idx] = state__[11][5][_mask_idx];
    stateR__[11][6][_mask_idx] = state__[11][6][_mask_idx];
    stateR__[11][7][_mask_idx] = state__[11][7][_mask_idx];
    stateR__[12][0][_mask_idx] = state__[12][0][_mask_idx];
    stateR__[12][1][_mask_idx] = state__[12][1][_mask_idx];
    stateR__[12][2][_mask_idx] = state__[12][2][_mask_idx];
    stateR__[12][3][_mask_idx] = state__[12][3][_mask_idx];
    stateR__[12][4][_mask_idx] = state__[12][4][_mask_idx];
    stateR__[12][5][_mask_idx] = state__[12][5][_mask_idx];
    stateR__[12][6][_mask_idx] = state__[12][6][_mask_idx];
    stateR__[12][7][_mask_idx] = state__[12][7][_mask_idx];
    stateR__[13][0][_mask_idx] = state__[13][0][_mask_idx];
    stateR__[13][1][_mask_idx] = state__[13][1][_mask_idx];
    stateR__[13][2][_mask_idx] = state__[13][2][_mask_idx];
    stateR__[13][3][_mask_idx] = state__[13][3][_mask_idx];
    stateR__[13][4][_mask_idx] = state__[13][4][_mask_idx];
    stateR__[13][5][_mask_idx] = state__[13][5][_mask_idx];
    stateR__[13][6][_mask_idx] = state__[13][6][_mask_idx];
    stateR__[13][7][_mask_idx] = state__[13][7][_mask_idx];
    stateR__[14][0][_mask_idx] = state__[14][0][_mask_idx];
    stateR__[14][1][_mask_idx] = state__[14][1][_mask_idx];
    stateR__[14][2][_mask_idx] = state__[14][2][_mask_idx];
    stateR__[14][3][_mask_idx] = state__[14][3][_mask_idx];
    stateR__[14][4][_mask_idx] = state__[14][4][_mask_idx];
    stateR__[14][5][_mask_idx] = state__[14][5][_mask_idx];
    stateR__[14][6][_mask_idx] = state__[14][6][_mask_idx];
    stateR__[14][7][_mask_idx] = state__[14][7][_mask_idx];
    stateR__[15][0][_mask_idx] = state__[15][0][_mask_idx];
    stateR__[15][1][_mask_idx] = state__[15][1][_mask_idx];
    stateR__[15][2][_mask_idx] = state__[15][2][_mask_idx];
    stateR__[15][3][_mask_idx] = state__[15][3][_mask_idx];
    stateR__[15][4][_mask_idx] = state__[15][4][_mask_idx];
    stateR__[15][5][_mask_idx] = state__[15][5][_mask_idx];
    stateR__[15][6][_mask_idx] = state__[15][6][_mask_idx];
    stateR__[15][7][_mask_idx] = state__[15][7][_mask_idx];
    stateR__[16][0][_mask_idx] = state__[16][0][_mask_idx];
    stateR__[16][1][_mask_idx] = state__[16][1][_mask_idx];
    stateR__[16][2][_mask_idx] = state__[16][2][_mask_idx];
    stateR__[16][3][_mask_idx] = state__[16][3][_mask_idx];
    stateR__[16][4][_mask_idx] = state__[16][4][_mask_idx];
    stateR__[16][5][_mask_idx] = state__[16][5][_mask_idx];
    stateR__[16][6][_mask_idx] = state__[16][6][_mask_idx];
    stateR__[16][7][_mask_idx] = state__[16][7][_mask_idx];
    stateR__[17][0][_mask_idx] = state__[17][0][_mask_idx];
    stateR__[17][1][_mask_idx] = state__[17][1][_mask_idx];
    stateR__[17][2][_mask_idx] = state__[17][2][_mask_idx];
    stateR__[17][3][_mask_idx] = state__[17][3][_mask_idx];
    stateR__[17][4][_mask_idx] = state__[17][4][_mask_idx];
    stateR__[17][5][_mask_idx] = state__[17][5][_mask_idx];
    stateR__[17][6][_mask_idx] = state__[17][6][_mask_idx];
    stateR__[17][7][_mask_idx] = state__[17][7][_mask_idx];
    stateR__[18][0][_mask_idx] = state__[18][0][_mask_idx];
    stateR__[18][1][_mask_idx] = state__[18][1][_mask_idx];
    stateR__[18][2][_mask_idx] = state__[18][2][_mask_idx];
    stateR__[18][3][_mask_idx] = state__[18][3][_mask_idx];
    stateR__[18][4][_mask_idx] = state__[18][4][_mask_idx];
    stateR__[18][5][_mask_idx] = state__[18][5][_mask_idx];
    stateR__[18][6][_mask_idx] = state__[18][6][_mask_idx];
    stateR__[18][7][_mask_idx] = state__[18][7][_mask_idx];
    stateR__[0][0][_mask_idx] = XOR(state__[0][0][_mask_idx],counter__[0][_mask_idx]);
    stateR__[0][1][_mask_idx] = XOR(state__[0][1][_mask_idx],counter__[1][_mask_idx]);
    stateR__[0][2][_mask_idx] = XOR(state__[0][2][_mask_idx],counter__[2][_mask_idx]);
    stateR__[0][3][_mask_idx] = XOR(state__[0][3][_mask_idx],counter__[3][_mask_idx]);
    stateR__[0][4][_mask_idx] = XOR(state__[0][4][_mask_idx],counter__[4][_mask_idx]);
    stateR__[0][5][_mask_idx] = XOR(state__[0][5][_mask_idx],counter__[5][_mask_idx]);
    stateR__[0][6][_mask_idx] = XOR(state__[0][6][_mask_idx],counter__[6][_mask_idx]);
    stateR__[0][7][_mask_idx] = XOR(state__[0][7][_mask_idx],counter__[7][_mask_idx]);
    stateR__[19][0][_mask_idx] = XOR(state__[19][0][_mask_idx],counter__[7][_mask_idx]);
    stateR__[19][1][_mask_idx] = XOR(state__[19][1][_mask_idx],counter__[6][_mask_idx]);
    stateR__[19][2][_mask_idx] = XOR(state__[19][2][_mask_idx],counter__[5][_mask_idx]);
    stateR__[19][3][_mask_idx] = XOR(state__[19][3][_mask_idx],counter__[4][_mask_idx]);
    stateR__[19][4][_mask_idx] = XOR(state__[19][4][_mask_idx],counter__[3][_mask_idx]);
    stateR__[19][5][_mask_idx] = XOR(state__[19][5][_mask_idx],counter__[2][_mask_idx]);
    stateR__[19][6][_mask_idx] = XOR(state__[19][6][_mask_idx],counter__[1][_mask_idx]);
    stateR__[19][7][_mask_idx] = XOR(state__[19][7][_mask_idx],counter__[0][_mask_idx]);
  }

}

void lfsr__B1 (/*inputs*/ DATATYPE counter__[8][MASKING_ORDER], /*outputs*/ DATATYPE counterR__[8][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp27_[MASKING_ORDER];

  // Instructions (body)
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    _tmp27_[_mask_idx] = XOR(counter__[1][_mask_idx],counter__[2][_mask_idx]);
    counterR__[1][_mask_idx] = counter__[2][_mask_idx];
    counterR__[2][_mask_idx] = counter__[3][_mask_idx];
    counterR__[3][_mask_idx] = counter__[4][_mask_idx];
    counterR__[4][_mask_idx] = counter__[5][_mask_idx];
    counterR__[5][_mask_idx] = counter__[6][_mask_idx];
    counterR__[6][_mask_idx] = counter__[7][_mask_idx];
    counterR__[7][_mask_idx] = _tmp27_[_mask_idx];
  }
  counterR__[0][0] = SET_ALL_ZERO();
  for (int _mask_idx = 1; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    counterR__[0][_mask_idx] = SET_ALL_ZERO();
  }

}

/* main function */
void permutation__ (/*inputs*/ DATATYPE input__[20][8][MASKING_ORDER], /*outputs*/ DATATYPE output__[20][8][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp30_[20][8][MASKING_ORDER];
  DATATYPE _tmp31_[20][8][MASKING_ORDER];
  DATATYPE counter__[8][MASKING_ORDER];
  DATATYPE state__[20][8][MASKING_ORDER];

  // Instructions (body)
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    state__[0][0][_mask_idx] = input__[0][0][_mask_idx];
    state__[0][1][_mask_idx] = input__[0][1][_mask_idx];
    state__[0][2][_mask_idx] = input__[0][2][_mask_idx];
    state__[0][3][_mask_idx] = input__[0][3][_mask_idx];
    state__[0][4][_mask_idx] = input__[0][4][_mask_idx];
    state__[0][5][_mask_idx] = input__[0][5][_mask_idx];
    state__[0][6][_mask_idx] = input__[0][6][_mask_idx];
    state__[0][7][_mask_idx] = input__[0][7][_mask_idx];
    state__[1][0][_mask_idx] = input__[1][0][_mask_idx];
    state__[1][1][_mask_idx] = input__[1][1][_mask_idx];
    state__[1][2][_mask_idx] = input__[1][2][_mask_idx];
    state__[1][3][_mask_idx] = input__[1][3][_mask_idx];
    state__[1][4][_mask_idx] = input__[1][4][_mask_idx];
    state__[1][5][_mask_idx] = input__[1][5][_mask_idx];
    state__[1][6][_mask_idx] = input__[1][6][_mask_idx];
    state__[1][7][_mask_idx] = input__[1][7][_mask_idx];
    state__[2][0][_mask_idx] = input__[2][0][_mask_idx];
    state__[2][1][_mask_idx] = input__[2][1][_mask_idx];
    state__[2][2][_mask_idx] = input__[2][2][_mask_idx];
    state__[2][3][_mask_idx] = input__[2][3][_mask_idx];
    state__[2][4][_mask_idx] = input__[2][4][_mask_idx];
    state__[2][5][_mask_idx] = input__[2][5][_mask_idx];
    state__[2][6][_mask_idx] = input__[2][6][_mask_idx];
    state__[2][7][_mask_idx] = input__[2][7][_mask_idx];
    state__[3][0][_mask_idx] = input__[3][0][_mask_idx];
    state__[3][1][_mask_idx] = input__[3][1][_mask_idx];
    state__[3][2][_mask_idx] = input__[3][2][_mask_idx];
    state__[3][3][_mask_idx] = input__[3][3][_mask_idx];
    state__[3][4][_mask_idx] = input__[3][4][_mask_idx];
    state__[3][5][_mask_idx] = input__[3][5][_mask_idx];
    state__[3][6][_mask_idx] = input__[3][6][_mask_idx];
    state__[3][7][_mask_idx] = input__[3][7][_mask_idx];
    state__[4][0][_mask_idx] = input__[4][0][_mask_idx];
    state__[4][1][_mask_idx] = input__[4][1][_mask_idx];
    state__[4][2][_mask_idx] = input__[4][2][_mask_idx];
    state__[4][3][_mask_idx] = input__[4][3][_mask_idx];
    state__[4][4][_mask_idx] = input__[4][4][_mask_idx];
    state__[4][5][_mask_idx] = input__[4][5][_mask_idx];
    state__[4][6][_mask_idx] = input__[4][6][_mask_idx];
    state__[4][7][_mask_idx] = input__[4][7][_mask_idx];
    state__[5][0][_mask_idx] = input__[5][0][_mask_idx];
    state__[5][1][_mask_idx] = input__[5][1][_mask_idx];
    state__[5][2][_mask_idx] = input__[5][2][_mask_idx];
    state__[5][3][_mask_idx] = input__[5][3][_mask_idx];
    state__[5][4][_mask_idx] = input__[5][4][_mask_idx];
    state__[5][5][_mask_idx] = input__[5][5][_mask_idx];
    state__[5][6][_mask_idx] = input__[5][6][_mask_idx];
    state__[5][7][_mask_idx] = input__[5][7][_mask_idx];
    state__[6][0][_mask_idx] = input__[6][0][_mask_idx];
    state__[6][1][_mask_idx] = input__[6][1][_mask_idx];
    state__[6][2][_mask_idx] = input__[6][2][_mask_idx];
    state__[6][3][_mask_idx] = input__[6][3][_mask_idx];
    state__[6][4][_mask_idx] = input__[6][4][_mask_idx];
    state__[6][5][_mask_idx] = input__[6][5][_mask_idx];
    state__[6][6][_mask_idx] = input__[6][6][_mask_idx];
    state__[6][7][_mask_idx] = input__[6][7][_mask_idx];
    state__[7][0][_mask_idx] = input__[7][0][_mask_idx];
    state__[7][1][_mask_idx] = input__[7][1][_mask_idx];
    state__[7][2][_mask_idx] = input__[7][2][_mask_idx];
    state__[7][3][_mask_idx] = input__[7][3][_mask_idx];
    state__[7][4][_mask_idx] = input__[7][4][_mask_idx];
    state__[7][5][_mask_idx] = input__[7][5][_mask_idx];
    state__[7][6][_mask_idx] = input__[7][6][_mask_idx];
    state__[7][7][_mask_idx] = input__[7][7][_mask_idx];
    state__[8][0][_mask_idx] = input__[8][0][_mask_idx];
    state__[8][1][_mask_idx] = input__[8][1][_mask_idx];
    state__[8][2][_mask_idx] = input__[8][2][_mask_idx];
    state__[8][3][_mask_idx] = input__[8][3][_mask_idx];
    state__[8][4][_mask_idx] = input__[8][4][_mask_idx];
    state__[8][5][_mask_idx] = input__[8][5][_mask_idx];
    state__[8][6][_mask_idx] = input__[8][6][_mask_idx];
    state__[8][7][_mask_idx] = input__[8][7][_mask_idx];
    state__[9][0][_mask_idx] = input__[9][0][_mask_idx];
    state__[9][1][_mask_idx] = input__[9][1][_mask_idx];
    state__[9][2][_mask_idx] = input__[9][2][_mask_idx];
    state__[9][3][_mask_idx] = input__[9][3][_mask_idx];
    state__[9][4][_mask_idx] = input__[9][4][_mask_idx];
    state__[9][5][_mask_idx] = input__[9][5][_mask_idx];
    state__[9][6][_mask_idx] = input__[9][6][_mask_idx];
    state__[9][7][_mask_idx] = input__[9][7][_mask_idx];
    state__[10][0][_mask_idx] = input__[10][0][_mask_idx];
    state__[10][1][_mask_idx] = input__[10][1][_mask_idx];
    state__[10][2][_mask_idx] = input__[10][2][_mask_idx];
    state__[10][3][_mask_idx] = input__[10][3][_mask_idx];
    state__[10][4][_mask_idx] = input__[10][4][_mask_idx];
    state__[10][5][_mask_idx] = input__[10][5][_mask_idx];
    state__[10][6][_mask_idx] = input__[10][6][_mask_idx];
    state__[10][7][_mask_idx] = input__[10][7][_mask_idx];
    state__[11][0][_mask_idx] = input__[11][0][_mask_idx];
    state__[11][1][_mask_idx] = input__[11][1][_mask_idx];
    state__[11][2][_mask_idx] = input__[11][2][_mask_idx];
    state__[11][3][_mask_idx] = input__[11][3][_mask_idx];
    state__[11][4][_mask_idx] = input__[11][4][_mask_idx];
    state__[11][5][_mask_idx] = input__[11][5][_mask_idx];
    state__[11][6][_mask_idx] = input__[11][6][_mask_idx];
    state__[11][7][_mask_idx] = input__[11][7][_mask_idx];
    state__[12][0][_mask_idx] = input__[12][0][_mask_idx];
    state__[12][1][_mask_idx] = input__[12][1][_mask_idx];
    state__[12][2][_mask_idx] = input__[12][2][_mask_idx];
    state__[12][3][_mask_idx] = input__[12][3][_mask_idx];
    state__[12][4][_mask_idx] = input__[12][4][_mask_idx];
    state__[12][5][_mask_idx] = input__[12][5][_mask_idx];
    state__[12][6][_mask_idx] = input__[12][6][_mask_idx];
    state__[12][7][_mask_idx] = input__[12][7][_mask_idx];
    state__[13][0][_mask_idx] = input__[13][0][_mask_idx];
    state__[13][1][_mask_idx] = input__[13][1][_mask_idx];
    state__[13][2][_mask_idx] = input__[13][2][_mask_idx];
    state__[13][3][_mask_idx] = input__[13][3][_mask_idx];
    state__[13][4][_mask_idx] = input__[13][4][_mask_idx];
    state__[13][5][_mask_idx] = input__[13][5][_mask_idx];
    state__[13][6][_mask_idx] = input__[13][6][_mask_idx];
    state__[13][7][_mask_idx] = input__[13][7][_mask_idx];
    state__[14][0][_mask_idx] = input__[14][0][_mask_idx];
    state__[14][1][_mask_idx] = input__[14][1][_mask_idx];
    state__[14][2][_mask_idx] = input__[14][2][_mask_idx];
    state__[14][3][_mask_idx] = input__[14][3][_mask_idx];
    state__[14][4][_mask_idx] = input__[14][4][_mask_idx];
    state__[14][5][_mask_idx] = input__[14][5][_mask_idx];
    state__[14][6][_mask_idx] = input__[14][6][_mask_idx];
    state__[14][7][_mask_idx] = input__[14][7][_mask_idx];
    state__[15][0][_mask_idx] = input__[15][0][_mask_idx];
    state__[15][1][_mask_idx] = input__[15][1][_mask_idx];
    state__[15][2][_mask_idx] = input__[15][2][_mask_idx];
    state__[15][3][_mask_idx] = input__[15][3][_mask_idx];
    state__[15][4][_mask_idx] = input__[15][4][_mask_idx];
    state__[15][5][_mask_idx] = input__[15][5][_mask_idx];
    state__[15][6][_mask_idx] = input__[15][6][_mask_idx];
    state__[15][7][_mask_idx] = input__[15][7][_mask_idx];
    state__[16][0][_mask_idx] = input__[16][0][_mask_idx];
    state__[16][1][_mask_idx] = input__[16][1][_mask_idx];
    state__[16][2][_mask_idx] = input__[16][2][_mask_idx];
    state__[16][3][_mask_idx] = input__[16][3][_mask_idx];
    state__[16][4][_mask_idx] = input__[16][4][_mask_idx];
    state__[16][5][_mask_idx] = input__[16][5][_mask_idx];
    state__[16][6][_mask_idx] = input__[16][6][_mask_idx];
    state__[16][7][_mask_idx] = input__[16][7][_mask_idx];
    state__[17][0][_mask_idx] = input__[17][0][_mask_idx];
    state__[17][1][_mask_idx] = input__[17][1][_mask_idx];
    state__[17][2][_mask_idx] = input__[17][2][_mask_idx];
    state__[17][3][_mask_idx] = input__[17][3][_mask_idx];
    state__[17][4][_mask_idx] = input__[17][4][_mask_idx];
    state__[17][5][_mask_idx] = input__[17][5][_mask_idx];
    state__[17][6][_mask_idx] = input__[17][6][_mask_idx];
    state__[17][7][_mask_idx] = input__[17][7][_mask_idx];
    state__[18][0][_mask_idx] = input__[18][0][_mask_idx];
    state__[18][1][_mask_idx] = input__[18][1][_mask_idx];
    state__[18][2][_mask_idx] = input__[18][2][_mask_idx];
    state__[18][3][_mask_idx] = input__[18][3][_mask_idx];
    state__[18][4][_mask_idx] = input__[18][4][_mask_idx];
    state__[18][5][_mask_idx] = input__[18][5][_mask_idx];
    state__[18][6][_mask_idx] = input__[18][6][_mask_idx];
    state__[18][7][_mask_idx] = input__[18][7][_mask_idx];
    state__[19][0][_mask_idx] = input__[19][0][_mask_idx];
    state__[19][1][_mask_idx] = input__[19][1][_mask_idx];
    state__[19][2][_mask_idx] = input__[19][2][_mask_idx];
    state__[19][3][_mask_idx] = input__[19][3][_mask_idx];
    state__[19][4][_mask_idx] = input__[19][4][_mask_idx];
    state__[19][5][_mask_idx] = input__[19][5][_mask_idx];
    state__[19][6][_mask_idx] = input__[19][6][_mask_idx];
    state__[19][7][_mask_idx] = input__[19][7][_mask_idx];
  }
  counter__[0][0] = SET_ALL_ZERO();
  for (int _mask_idx = 1; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    counter__[0][_mask_idx] = SET_ALL_ZERO();
    counter__[1][_mask_idx] = SET_ALL_ZERO();
    counter__[2][_mask_idx] = SET_ALL_ZERO();
    counter__[3][_mask_idx] = SET_ALL_ZERO();
    counter__[4][_mask_idx] = SET_ALL_ZERO();
    counter__[5][_mask_idx] = SET_ALL_ZERO();
    counter__[6][_mask_idx] = SET_ALL_ZERO();
    counter__[7][_mask_idx] = SET_ALL_ZERO();
  }
  counter__[1][0] = SET_ALL_ONE();
  counter__[2][0] = SET_ALL_ONE();
  counter__[3][0] = SET_ALL_ONE();
  counter__[4][0] = SET_ALL_ZERO();
  counter__[5][0] = SET_ALL_ONE();
  counter__[6][0] = SET_ALL_ZERO();
  counter__[7][0] = SET_ALL_ONE();
  for (int i__ = 0; i__ <= 79; i__++) {
    counterLayer__B1(state__,counter__,_tmp30_);
    sBoxLayer__B1(_tmp30_,_tmp31_);
    pLayer__B1(_tmp31_,state__);
    lfsr__B1(counter__,counter__);
  }
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    output__[0][0][_mask_idx] = state__[0][0][_mask_idx];
    output__[0][1][_mask_idx] = state__[0][1][_mask_idx];
    output__[0][2][_mask_idx] = state__[0][2][_mask_idx];
    output__[0][3][_mask_idx] = state__[0][3][_mask_idx];
    output__[0][4][_mask_idx] = state__[0][4][_mask_idx];
    output__[0][5][_mask_idx] = state__[0][5][_mask_idx];
    output__[0][6][_mask_idx] = state__[0][6][_mask_idx];
    output__[0][7][_mask_idx] = state__[0][7][_mask_idx];
    output__[1][0][_mask_idx] = state__[1][0][_mask_idx];
    output__[1][1][_mask_idx] = state__[1][1][_mask_idx];
    output__[1][2][_mask_idx] = state__[1][2][_mask_idx];
    output__[1][3][_mask_idx] = state__[1][3][_mask_idx];
    output__[1][4][_mask_idx] = state__[1][4][_mask_idx];
    output__[1][5][_mask_idx] = state__[1][5][_mask_idx];
    output__[1][6][_mask_idx] = state__[1][6][_mask_idx];
    output__[1][7][_mask_idx] = state__[1][7][_mask_idx];
    output__[2][0][_mask_idx] = state__[2][0][_mask_idx];
    output__[2][1][_mask_idx] = state__[2][1][_mask_idx];
    output__[2][2][_mask_idx] = state__[2][2][_mask_idx];
    output__[2][3][_mask_idx] = state__[2][3][_mask_idx];
    output__[2][4][_mask_idx] = state__[2][4][_mask_idx];
    output__[2][5][_mask_idx] = state__[2][5][_mask_idx];
    output__[2][6][_mask_idx] = state__[2][6][_mask_idx];
    output__[2][7][_mask_idx] = state__[2][7][_mask_idx];
    output__[3][0][_mask_idx] = state__[3][0][_mask_idx];
    output__[3][1][_mask_idx] = state__[3][1][_mask_idx];
    output__[3][2][_mask_idx] = state__[3][2][_mask_idx];
    output__[3][3][_mask_idx] = state__[3][3][_mask_idx];
    output__[3][4][_mask_idx] = state__[3][4][_mask_idx];
    output__[3][5][_mask_idx] = state__[3][5][_mask_idx];
    output__[3][6][_mask_idx] = state__[3][6][_mask_idx];
    output__[3][7][_mask_idx] = state__[3][7][_mask_idx];
    output__[4][0][_mask_idx] = state__[4][0][_mask_idx];
    output__[4][1][_mask_idx] = state__[4][1][_mask_idx];
    output__[4][2][_mask_idx] = state__[4][2][_mask_idx];
    output__[4][3][_mask_idx] = state__[4][3][_mask_idx];
    output__[4][4][_mask_idx] = state__[4][4][_mask_idx];
    output__[4][5][_mask_idx] = state__[4][5][_mask_idx];
    output__[4][6][_mask_idx] = state__[4][6][_mask_idx];
    output__[4][7][_mask_idx] = state__[4][7][_mask_idx];
    output__[5][0][_mask_idx] = state__[5][0][_mask_idx];
    output__[5][1][_mask_idx] = state__[5][1][_mask_idx];
    output__[5][2][_mask_idx] = state__[5][2][_mask_idx];
    output__[5][3][_mask_idx] = state__[5][3][_mask_idx];
    output__[5][4][_mask_idx] = state__[5][4][_mask_idx];
    output__[5][5][_mask_idx] = state__[5][5][_mask_idx];
    output__[5][6][_mask_idx] = state__[5][6][_mask_idx];
    output__[5][7][_mask_idx] = state__[5][7][_mask_idx];
    output__[6][0][_mask_idx] = state__[6][0][_mask_idx];
    output__[6][1][_mask_idx] = state__[6][1][_mask_idx];
    output__[6][2][_mask_idx] = state__[6][2][_mask_idx];
    output__[6][3][_mask_idx] = state__[6][3][_mask_idx];
    output__[6][4][_mask_idx] = state__[6][4][_mask_idx];
    output__[6][5][_mask_idx] = state__[6][5][_mask_idx];
    output__[6][6][_mask_idx] = state__[6][6][_mask_idx];
    output__[6][7][_mask_idx] = state__[6][7][_mask_idx];
    output__[7][0][_mask_idx] = state__[7][0][_mask_idx];
    output__[7][1][_mask_idx] = state__[7][1][_mask_idx];
    output__[7][2][_mask_idx] = state__[7][2][_mask_idx];
    output__[7][3][_mask_idx] = state__[7][3][_mask_idx];
    output__[7][4][_mask_idx] = state__[7][4][_mask_idx];
    output__[7][5][_mask_idx] = state__[7][5][_mask_idx];
    output__[7][6][_mask_idx] = state__[7][6][_mask_idx];
    output__[7][7][_mask_idx] = state__[7][7][_mask_idx];
    output__[8][0][_mask_idx] = state__[8][0][_mask_idx];
    output__[8][1][_mask_idx] = state__[8][1][_mask_idx];
    output__[8][2][_mask_idx] = state__[8][2][_mask_idx];
    output__[8][3][_mask_idx] = state__[8][3][_mask_idx];
    output__[8][4][_mask_idx] = state__[8][4][_mask_idx];
    output__[8][5][_mask_idx] = state__[8][5][_mask_idx];
    output__[8][6][_mask_idx] = state__[8][6][_mask_idx];
    output__[8][7][_mask_idx] = state__[8][7][_mask_idx];
    output__[9][0][_mask_idx] = state__[9][0][_mask_idx];
    output__[9][1][_mask_idx] = state__[9][1][_mask_idx];
    output__[9][2][_mask_idx] = state__[9][2][_mask_idx];
    output__[9][3][_mask_idx] = state__[9][3][_mask_idx];
    output__[9][4][_mask_idx] = state__[9][4][_mask_idx];
    output__[9][5][_mask_idx] = state__[9][5][_mask_idx];
    output__[9][6][_mask_idx] = state__[9][6][_mask_idx];
    output__[9][7][_mask_idx] = state__[9][7][_mask_idx];
    output__[10][0][_mask_idx] = state__[10][0][_mask_idx];
    output__[10][1][_mask_idx] = state__[10][1][_mask_idx];
    output__[10][2][_mask_idx] = state__[10][2][_mask_idx];
    output__[10][3][_mask_idx] = state__[10][3][_mask_idx];
    output__[10][4][_mask_idx] = state__[10][4][_mask_idx];
    output__[10][5][_mask_idx] = state__[10][5][_mask_idx];
    output__[10][6][_mask_idx] = state__[10][6][_mask_idx];
    output__[10][7][_mask_idx] = state__[10][7][_mask_idx];
    output__[11][0][_mask_idx] = state__[11][0][_mask_idx];
    output__[11][1][_mask_idx] = state__[11][1][_mask_idx];
    output__[11][2][_mask_idx] = state__[11][2][_mask_idx];
    output__[11][3][_mask_idx] = state__[11][3][_mask_idx];
    output__[11][4][_mask_idx] = state__[11][4][_mask_idx];
    output__[11][5][_mask_idx] = state__[11][5][_mask_idx];
    output__[11][6][_mask_idx] = state__[11][6][_mask_idx];
    output__[11][7][_mask_idx] = state__[11][7][_mask_idx];
    output__[12][0][_mask_idx] = state__[12][0][_mask_idx];
    output__[12][1][_mask_idx] = state__[12][1][_mask_idx];
    output__[12][2][_mask_idx] = state__[12][2][_mask_idx];
    output__[12][3][_mask_idx] = state__[12][3][_mask_idx];
    output__[12][4][_mask_idx] = state__[12][4][_mask_idx];
    output__[12][5][_mask_idx] = state__[12][5][_mask_idx];
    output__[12][6][_mask_idx] = state__[12][6][_mask_idx];
    output__[12][7][_mask_idx] = state__[12][7][_mask_idx];
    output__[13][0][_mask_idx] = state__[13][0][_mask_idx];
    output__[13][1][_mask_idx] = state__[13][1][_mask_idx];
    output__[13][2][_mask_idx] = state__[13][2][_mask_idx];
    output__[13][3][_mask_idx] = state__[13][3][_mask_idx];
    output__[13][4][_mask_idx] = state__[13][4][_mask_idx];
    output__[13][5][_mask_idx] = state__[13][5][_mask_idx];
    output__[13][6][_mask_idx] = state__[13][6][_mask_idx];
    output__[13][7][_mask_idx] = state__[13][7][_mask_idx];
    output__[14][0][_mask_idx] = state__[14][0][_mask_idx];
    output__[14][1][_mask_idx] = state__[14][1][_mask_idx];
    output__[14][2][_mask_idx] = state__[14][2][_mask_idx];
    output__[14][3][_mask_idx] = state__[14][3][_mask_idx];
    output__[14][4][_mask_idx] = state__[14][4][_mask_idx];
    output__[14][5][_mask_idx] = state__[14][5][_mask_idx];
    output__[14][6][_mask_idx] = state__[14][6][_mask_idx];
    output__[14][7][_mask_idx] = state__[14][7][_mask_idx];
    output__[15][0][_mask_idx] = state__[15][0][_mask_idx];
    output__[15][1][_mask_idx] = state__[15][1][_mask_idx];
    output__[15][2][_mask_idx] = state__[15][2][_mask_idx];
    output__[15][3][_mask_idx] = state__[15][3][_mask_idx];
    output__[15][4][_mask_idx] = state__[15][4][_mask_idx];
    output__[15][5][_mask_idx] = state__[15][5][_mask_idx];
    output__[15][6][_mask_idx] = state__[15][6][_mask_idx];
    output__[15][7][_mask_idx] = state__[15][7][_mask_idx];
    output__[16][0][_mask_idx] = state__[16][0][_mask_idx];
    output__[16][1][_mask_idx] = state__[16][1][_mask_idx];
    output__[16][2][_mask_idx] = state__[16][2][_mask_idx];
    output__[16][3][_mask_idx] = state__[16][3][_mask_idx];
    output__[16][4][_mask_idx] = state__[16][4][_mask_idx];
    output__[16][5][_mask_idx] = state__[16][5][_mask_idx];
    output__[16][6][_mask_idx] = state__[16][6][_mask_idx];
    output__[16][7][_mask_idx] = state__[16][7][_mask_idx];
    output__[17][0][_mask_idx] = state__[17][0][_mask_idx];
    output__[17][1][_mask_idx] = state__[17][1][_mask_idx];
    output__[17][2][_mask_idx] = state__[17][2][_mask_idx];
    output__[17][3][_mask_idx] = state__[17][3][_mask_idx];
    output__[17][4][_mask_idx] = state__[17][4][_mask_idx];
    output__[17][5][_mask_idx] = state__[17][5][_mask_idx];
    output__[17][6][_mask_idx] = state__[17][6][_mask_idx];
    output__[17][7][_mask_idx] = state__[17][7][_mask_idx];
    output__[18][0][_mask_idx] = state__[18][0][_mask_idx];
    output__[18][1][_mask_idx] = state__[18][1][_mask_idx];
    output__[18][2][_mask_idx] = state__[18][2][_mask_idx];
    output__[18][3][_mask_idx] = state__[18][3][_mask_idx];
    output__[18][4][_mask_idx] = state__[18][4][_mask_idx];
    output__[18][5][_mask_idx] = state__[18][5][_mask_idx];
    output__[18][6][_mask_idx] = state__[18][6][_mask_idx];
    output__[18][7][_mask_idx] = state__[18][7][_mask_idx];
    output__[19][0][_mask_idx] = state__[19][0][_mask_idx];
    output__[19][1][_mask_idx] = state__[19][1][_mask_idx];
    output__[19][2][_mask_idx] = state__[19][2][_mask_idx];
    output__[19][3][_mask_idx] = state__[19][3][_mask_idx];
    output__[19][4][_mask_idx] = state__[19][4][_mask_idx];
    output__[19][5][_mask_idx] = state__[19][5][_mask_idx];
    output__[19][6][_mask_idx] = state__[19][6][_mask_idx];
    output__[19][7][_mask_idx] = state__[19][7][_mask_idx];
  }

}

/* Additional functions */
uint32_t bench_speed() {
  /* inputs */
  DATATYPE input__[20][8][MASKING_ORDER] = { 0 };
  /* outputs */
  DATATYPE output__[20][8][MASKING_ORDER] = { 0 };
  /* fun call */
  permutation__(input__,output__);

  /* Returning the number of encrypted bytes */
  return 640;
}

/* **************************************************************** */
/*                            Usuba source                          */
/*                                                                  */
/*

 table sBox(x :  b4 :: base)
  returns y :  b4 :: base
{
  14, 13, 11, 0, 2, 1, 4, 15, 7, 10, 8, 5, 9, 12, 3, 6
}


 node sBoxLayer(state :  b8[20] :: base)
  returns stateR :  b8[20] :: base
vars

let
  forall i in [0,19] {
    (stateR[i][0 .. 3]) = sBox(state[i][0 .. 3]);
    (stateR[i][4 .. 7]) = sBox(state[i][4 .. 7])
  }
tel

 node pLayer(state :  b8[20] :: base)
  returns stateR :  b8[20] :: base
vars
  x :  b1[160] :: base,
  PermutedBitNo :  nat :: base,
  y :  nat :: base
let
  forall i in [0,18] {
    forall j in [0,7] {
      (x[((i * 8) + j)]) = state[i][(7 - j)];
      (stateR[(((((8 * i) + j) * 40) % 159) / 8)][(7 - (((((8 * i) + j) * 40) % 159) - (8 * (((((8 * i) + j) * 40) % 159) / 8))))]) = x[((i * 8) + j)]
    }
  };
  forall j in [0,6] {
    (x[((19 * 8) + j)]) = state[19][(7 - j)];
    (stateR[(((((8 * 19) + j) * 40) % 159) / 8)][(7 - (((((8 * 19) + j) * 40) % 159) - (8 * (((((8 * 19) + j) * 40) % 159) / 8))))]) = x[((19 * 8) + j)]
  };
  (stateR[19][0]) = state[19][0]
tel

 node counterLayer(state :  b8[20] :: base,counter :  b8 :: base)
  returns stateR :  b8[20] :: base
vars

let
  (stateR[1 .. 18]) = state[1 .. 18];
  (stateR[0]) = (state[0] ^ counter);
  (stateR[19]) = (state[19] ^ counter[7 .. 0])
tel

 node lfsr(counter :  b8 :: base)
  returns counterR :  b8 :: base
vars

let
  (counterR) = (((counter << 1) | (((64 & counter) >> 6) ^ ((32 & counter) >> 5))) & 127)
tel

 node permutation(input :  b8[20] :: base)
  returns output :  b8[20] :: base
vars
  state :  b8[81][20] :: base,
  counter :  b8[81] :: base
let
  (state[0]) = input;
  (counter[0]) = 117;
  forall i in [0,79] {
    (state[(i + 1)]) = pLayer(sBoxLayer(counterLayer(state[i],counter[i])));
    (counter[(i + 1)]) = lfsr(counter[i])
  };
  (output) = state[80]
tel

*/
 