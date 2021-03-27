/* ArduinoRubberduckyPayload: Library for executing Rubberducky payloads on an Arduino 
Copyright (C) 2020-2021  Philipp Leclercq

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include "Arduino.h"
#include "RubberduckyPayload.h"
#if defined(_USING_HID)

static const uint8_t _hidReportDescriptor[] PROGMEM = {

  //  Keyboard
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)  // 47
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x02,                    //   REPORT_ID (2)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)

  0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)

  0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)

  0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x73,                    //   LOGICAL_MAXIMUM (115)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)

  0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x73,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0,                          // END_COLLECTION
};

RubberduckyPayload_::RubberduckyPayload_(void) {
  static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
	HID().AppendDescriptor(&node);
}

void RubberduckyPayload_::sendReport(KeyReport* keys)
{
	HID().SendReport(2,keys,sizeof(KeyReport));
}

void RubberduckyPayload_::execute(uint16_t len, uint16_t addr) {
  //parse raw duckencoder script
  for (int i=0; i<len; i+=2)
  {
    uint8_t key = pgm_read_byte_near(addr + i);
    uint8_t mod = pgm_read_byte_near(addr + i+1);
    if (key == 0) //delay (a delay>255 is split into a sequence of delays)
    {
      delay(mod);
    }
    else {
        _keyReport.key = key;
        _keyReport.modifiers = mod;
        sendReport(&_keyReport);
        _keyReport.key = 0;
        _keyReport.modifiers = 0;
        sendReport(&_keyReport);
    }
  }
}

RubberduckyPayload_ RubberduckyPayload;

#endif
