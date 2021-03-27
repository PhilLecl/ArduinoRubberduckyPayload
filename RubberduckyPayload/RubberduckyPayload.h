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
#ifndef RUBBERDUCKY_PAYLOAD
#define RUBBERDUCKY_PAYLOAD
#include "HID.h"
#if !defined(_USING_HID)
#warning "Using legacy HID core (non pluggable)"
#else


//  Low level key report: up to 6 keys and shift, ctrl etc at once
typedef struct
{
  uint8_t modifiers;
  uint8_t reserved;
  uint8_t key;
} KeyReport;

class RubberduckyPayload_
{
public:
  void execute(uint16_t len, uint16_t addr);
private:
  RubberduckyPayload_(void);
  KeyReport _keyReport;
  void sendReport(KeyReport* keys);
};
extern RubberduckyPayload_ RubberduckyPayload;

#endif
#endif
