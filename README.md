# ArduinoRubberduckyPayload

Run Rubberducky payloads on an Arduino.

## Usage

1. Install the Arduino library by going to *Sketch>Include Library>Add .ZIP Library* in the Arduino IDE and selecting
   the `RubberduckyPayload` folder.
2. Convert an [encoded](https://github.com/hak5darren/USB-Rubber-Ducky/blob/master/Encoder/encoder.jar) Rubberducky
   payload to an Arduino array: `$ ./bin2array.py BIN_FILE [CHUNK_SIZE]`
3. In the Arduino IDE, open *File>Examples>RubberduckyPayload>template* and paste the output of `bin2array.py` at the
   marked spot.

### Example output of `bin2array.py`

    const unsigned int duckraw_size = 22;
    const PROGMEM uint8_t duckraw [duckraw_size] = {
      0xb, 0x2, 0x8, 0x0, 0xf, 0x0, 0xf, 0x0, 0x12, 0x0, 0x2c, 0x0, 0x1a, 0x2, 0x12, 0x0, 0x15, 0x0, 0xf, 0x0,
      0x7, 0x0
    };

### Template sketch

    #include "RubberduckyPayload.h"
    
    // Paste the output of the Python script here.
    
    void setup() {
      delay(1000); // 1 second delay in order to give the computer time to recognise the Arduino.
      RubberduckyPayload.execute(duckraw_size, duckraw); // Execute the payload.
    }
    
    void loop() {} // As the payload should only be executed once, void loop stays empty

## Credits

This project was inspired by [duck2spark by MaMe82 (Marcus Mengs)](https://github.com/mame82/duck2spark).

The `RubberduckyPayload` Arduino library uses code from
the [Arduino Keyboard library](https://github.com/arduino-libraries/Keyboard).