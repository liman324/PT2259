#include <Arduino.h>
#include <Wire.h>
#include "PT2259.h"

PT2259::PT2259(){
	Wire.begin();
}

void PT2259::setVol_ch2(bool mute, int vol_ch){
     vol_ch = 79 - vol_ch;
     byte vol_ch_10 = vol_ch/10;
     byte vol_ch_1 = vol_ch%10;

     if(mute==0){writeWire(MUTE_OFF, CH2_10+vol_ch_10, CH2_1+vol_ch_1);}	
     if(mute==1){writeWire(MUTE_ON, CH2_10+vol_ch_10, CH2_1+vol_ch_1);}
}

void PT2259::setVol_left(bool mute, int vol_l){
     vol_l = 79 - vol_l;
     byte vol_l_10 = vol_l/10;
     byte vol_l_1 = vol_l%10;

     if(mute==0){writeWire(MUTE_OFF, LEFT_10+vol_l_10, LEFT_1+vol_l_1);}	
     if(mute==1){writeWire(MUTE_L, LEFT_10+vol_l_10, LEFT_1+vol_l_1);}
}

void PT2259::setVol_right(bool mute, int vol_r){
     vol_r = 79 - vol_r;
     byte vol_r_10 = vol_r/10;
     byte vol_r_1 = vol_r%10;

     if(mute==0){writeWire(MUTE_OFF, RIGHT_10+vol_r_10, RIGHT_1+vol_r_1);}	
     if(mute==1){writeWire(MUTE_R, RIGHT_10+vol_r_10, RIGHT_1+vol_r_1);}
}

void PT2259::clear(){
  Wire.beginTransmission(PT2259_address);
  Wire.write (CLEAR);// clear
  Wire.endTransmission();	
}

void PT2259::writeWire(int8_t a, int8_t b, int8_t c){
  Wire.beginTransmission(PT2259_address);
  Wire.write (CLEAR);// clear	
  Wire.write (a);    // mute
  Wire.write (b);    // 10 dB
  Wire.write (c);    // 1 dB
  Wire.endTransmission();
}
