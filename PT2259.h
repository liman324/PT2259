#ifndef PT2259_H
#define PT2259_H
#define PT2259_address 0b1000100

//Sub addresses
#define CLEAR        0xF0
#define MUTE_OFF     0x74
#define MUTE_ON      0x77

#define MUTE_R      0x75
#define MUTE_L      0x76

#define CH2_1        0b11010000
#define CH2_10       0b11100000

#define LEFT_1       0b10100000
#define LEFT_10      0b10110000

#define RIGHT_1      0b00100000
#define RIGHT_10     0b00110000


#include <Arduino.h>
class PT2259{
public:
PT2259();

void setVol_ch2(bool mute, int vol_ch);
void setVol_left(bool mute, int vol_l);
void setVol_right(bool mute, int vol_r);

private:
void writeWire(int8_t a, int8_t b, int8_t c);
};
#endif //PT2259_H
