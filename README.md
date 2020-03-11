# ArduinoRubberduckyPayload
This project consists of an Arduino library ("RubberduckyPayload") which provides a function able to execute an encoded USB-Rubber-Ducky payload as well as a simple Python script ("bintoarray.py") to convert an encoded payload into text that can be pasted into an Arduino sketch so that it can be used by the library.

## Contents
* ### RubberduckyPayload
  This folder contains the aforementioned Arduino library.  
  The library uses parts of the official [Arduino Keyboard library](https://github.com/arduino-libraries/Keyboard).
* ### BinToArray
  This folder contains the aforementioned Python script.

## Usage
In order to use the RubberduckyPayload Arduino library, you need to clone/download the project, open the Arduino IDE, navigate to *Sketch > Include Library > Add .ZIP Library* and the select the "RubberduckyPayload" folder.  
You will then be able to use the library by adding `#include "RubberduckyPayload.h"` to the beginning of your sketch.

The library basically only provides a single function, `RubberduckyPayload.execute(duckraw_size, duckraw)`, where "duckraw_size" is the number of bytes the payload contains and "duckraw" is an array of bytes (uint8_t) stored in the program memory.

In order to use the Python script, you need to have a functioning Python3 installation. You can the execute it by opening a terminal / command line and typing `python3 <path to the script> <path to the encoded Rubberducky payload> [maximum number of bytes to put into a single line]`. The last parameter is optional and defaults to 20.  
As the script has a shebang at the beginning, you can also make it executable (`chmod +x bintoarray.py`) and run it directly (`./bintoarray.py <encoded payload> [max. number of bytes per line]`).

## Template
You can use this basic template for your Arduino sketches:

    #include "RubberduckyPayload.h"
    
    // Paste the output of the Python script here.
    
    void setup() {
        delay(1000); // 1 second delay in order to give the computer time to recognise the Arduino.
        RubberduckyPayload.execute(duckraw_size, duckraw); // Execute the payload.
    }
  
    void loop() {} // As the payload should only be executed once, void loop stays empty

This template can also be found in the Arduino IDE under *File > Examples > RubberduckyPayload > template* once the library is installed.

## Inspiration

This project was inspired by [duck2spark by MaMe82 (Marcus Mengs)](https://github.com/mame82/duck2spark#duck2spark-by-mame82-marcus-mengs) who developed a similar project for the Digispark.
