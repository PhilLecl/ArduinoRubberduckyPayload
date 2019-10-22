#include "RubberduckyPayload.h"

// Paste the output of the Python script here.

void setup() {
    delay(1000); // 1 second delay in order to give the computer time to recognise the Arduino.
    RubberduckyPayload.execute(duckraw_size, duckraw); // Execute the payload.
}

void loop() {} // As the payload should only be executed once, void loop stays empty
