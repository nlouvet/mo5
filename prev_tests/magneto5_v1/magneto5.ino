
#include <Arduino.h>

#define LEDPIN 13
#define DATAOUT 3
#define MOTOPIN 4

// const PROGMEM byte k7[], NUM_FULL_BLOCKS and SIZE_LAST_BLOCK are defined in the header
#include "squash.h"


/*
const PROGMEM byte k7[] = {
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x3C, 0x5A,
  0x00, 0x10, 0x54, 0x45, 0x53, 0x54, 0x20, 0x20, 0x20, 0x20, 0x42, 0x41, 0x53, 0x00, 0xFF, 0xFF, 0x6C,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x3C, 0x5A,
  0x01, 0x00, 0x0D, 0x31, 0x30, 0x20, 0x46, 0x4F, 0x52, 0x20, 0x49, 0x3D, 0x31, 0x20, 0x54, 0x4F, 0x20, 0x31, 0x30, 0x0D, 0x32, 0x30, 0x20, 0x46, 0x4F, 0x52, 0x20, 0x4A, 0x3D, 0x31, 0x20, 0x54, 0x4F, 0x20, 0x49, 0x0D, 0x33, 0x30, 0x20, 0x50, 0x52, 0x49, 0x4E, 0x54, 0x20, 0x22, 0x2A, 0x22, 0x3B, 0x0D, 0x34, 0x30, 0x20, 0x4E, 0x45, 0x58, 0x54, 0x20, 0x4A, 0x0D, 0x35, 0x30, 0x20, 0x50, 0x52, 0x49, 0x4E, 0x54, 0x0D, 0x36, 0x30, 0x20, 0x4E, 0x45, 0x58, 0x54, 0x20, 0x49, 0x0D, 0x37, 0x30, 0x20, 0x46, 0x4F, 0x52, 0x20, 0x49, 0x3D, 0x31, 0x30, 0x20, 0x54, 0x4F, 0x20, 0x31, 0x20, 0x53, 0x54, 0x45, 0x50, 0x20, 0x2D, 0x31, 0x0D, 0x38, 0x30, 0x20, 0x46, 0x4F, 0x52, 0x20, 0x4A, 0x3D, 0x31, 0x20, 0x54, 0x4F, 0x20, 0x49, 0x0D, 0x39, 0x30, 0x20, 0x50, 0x52, 0x49, 0x4E, 0x54, 0x20, 0x22, 0x2A, 0x22, 0x3B, 0x0D, 0x31, 0x30, 0x30, 0x20, 0x4E, 0x45, 0x58, 0x54, 0x20, 0x4A, 0x0D, 0x31, 0x31, 0x30, 0x20, 0x50, 0x52, 0x49, 0x4E, 0x54, 0x0D, 0x31, 0x32, 0x30, 0x20, 0x4E, 0x45, 0x58, 0x54, 0x20, 0x49, 0x0D, 0x31, 0x33, 0x30, 0x20, 0x46, 0x4F, 0x52, 0x20, 0x49, 0x3D, 0x31, 0x20, 0x54, 0x4F, 0x20, 0x31, 0x30, 0x0D, 0x31, 0x34, 0x30, 0x20, 0x46, 0x4F, 0x52, 0x20, 0x4A, 0x3D, 0x31, 0x20, 0x54, 0x4F, 0x20, 0x49, 0x0D, 0x31, 0x35, 0x30, 0x20, 0x50, 0x52, 0x49, 0x4E, 0x54, 0x20, 0x22, 0x20, 0x22, 0x3B, 0x0D, 0x31, 0x36, 0x30, 0x20, 0x4E, 0x45, 0x58, 0x54, 0x20, 0x4A, 0x0D, 0x31, 0x37, 0x30, 0x20, 0x50, 0x52, 0x49, 0x4E, 0x54, 0x20, 0x22, 0x23, 0x22, 0x0D, 0x31, 0x38, 0x30, 0x20, 0x4E, 0x45, 0x58, 0x54, 0x20, 0x49, 0x0D, 0x31, 0x39, 0x30, 0x20, 0x8B,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x3C, 0x5A,
  0x01, 0x5C, 0x46, 0x4F, 0x52, 0x20, 0x49, 0x3D, 0x31, 0x30, 0x20, 0x54, 0x4F, 0x20, 0x31, 0x20, 0x53, 0x54, 0x45, 0x50, 0x20, 0x2D, 0x31, 0x0D, 0x32, 0x30, 0x30, 0x20, 0x46, 0x4F, 0x52, 0x20, 0x4A, 0x3D, 0x31, 0x20, 0x54, 0x4F, 0x20, 0x49, 0x0D, 0x32, 0x31, 0x30, 0x20, 0x50, 0x52, 0x49, 0x4E, 0x54, 0x20, 0x22, 0x20, 0x22, 0x3B, 0x0D, 0x32, 0x32, 0x30, 0x20, 0x4E, 0x45, 0x58, 0x54, 0x20, 0x4A, 0x0D, 0x32, 0x33, 0x30, 0x20, 0x50, 0x52, 0x49, 0x4E, 0x54, 0x20, 0x22, 0x23, 0x22, 0x0D, 0x32, 0x34, 0x30, 0x20, 0x4E, 0x45, 0x58, 0x54, 0x20, 0x49, 0x0D, 0xB6,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x3C, 0x5A, 0xFF, 0x02, 0x00
};
*/

const unsigned long taille_k7 = sizeof(k7);
unsigned long position;
byte state = 0x00;
uint16_t curbyte = 0x0000;

void reset_datout() {
  state = 0x01;
  digitalWrite(DATAOUT, state);
}

void toggle_datout() {
  state ^= 0x01;
  digitalWrite(DATAOUT, state);

}

void readk7(uint16_t len) {
  for(uint16_t i = 0; i < len; i++) {
    byte w = pgm_read_byte(k7+curbyte);
    for(uint8_t j = 0; j < 8; j++) {
      toggle_datout();
      delayMicroseconds(395);
      if(w & 0x80) toggle_datout();
      delayMicroseconds(395);
      w <<= 1;
    }
    curbyte++;
  }
  //digitalWrite(DATAOUT, HIGH);
  reset_datout();
}

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(DATAOUT, OUTPUT);
  pinMode(MOTOPIN, INPUT);
  curbyte = 0x0000;

  // at the begining, the state is 0, but
  // the DATAOUT pin is set to high
  //state = 0x00;
  //digitalWrite(DATAOUT, HIGH);
  reset_datout();

  while(digitalRead(MOTOPIN) == HIGH);
  digitalWrite(LEDPIN, HIGH);
  delay(2500);
  
  readk7(35);
  delay(2500);

  for(unsigned int i=0; i<NUM_FULL_BLOCKS; i++) {
    readk7(275);
    delay(160);
  }

  readk7(SIZE_LAST_BLOCK);
  delay(160);

  readk7(21);

 // while(!digitalRead(MOTOPIN));
}

void loop() {
  digitalWrite(LEDPIN, LOW);
  delay(100);
  digitalWrite(LEDPIN, HIGH);
  delay(100);
}
