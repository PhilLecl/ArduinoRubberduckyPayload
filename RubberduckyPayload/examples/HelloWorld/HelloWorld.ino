#include "RubberduckyPayload.h"

const unsigned int duckraw_size =  22  ;
const PROGMEM uint8_t duckraw [duckraw_size] = {
0xb,0x2,0x8,0x0,0xf,0x0,0xf,0x0,0x12,0x0,0x2c,0x0,0x1a,0x2,0x12,
0x0,0x15,0x0,0xf,0x0,0x7,0x0
};

void setup() {
    delay(1000); // 1 second delay in order to give the computer time to recognise the Arduino.
    RubberduckyPayload.execute(duckraw_size, duckraw); // Execute the payload.
}

void loop() {} // As the payload should only be executed once, void loop stays empty
