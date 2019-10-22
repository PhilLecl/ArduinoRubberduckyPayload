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
