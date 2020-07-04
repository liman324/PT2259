#include <Wire.h>
#include <PT2259.h>

 PT2259 pt;

void setup(){
  audio();
  }

void loop(){}

void audio(){
 pt.setVol_ch2(0, 79); // mute, vol
// mute on  === 1
// mute off === 0
// vol === -79...0 dB === int 0...79  

// channel-by-channel adjustment
// pt.setVol_left(0, 79);
// pt.setVol_right(0, 79);
  } 
