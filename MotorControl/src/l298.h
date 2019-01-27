#ifndef L298_H
#define L298_H

#include <mbed.h>

class l298 {

private:
  Mutex mu;

  DigitalOut ENA;
  DigitalOut ENB;
  DigitalOut IN1;
  DigitalOut IN2;
  DigitalOut IN3;
  DigitalOut IN4;

public:
// Constructor
l298(PinName ENA, PinName ENB, PinName IN1, PinName IN2, PinName IN3, PinName IN4);

// Methods
void enable_a(bool val);
void enable_b(bool val);
void in_1(bool val);
void in_2(bool val);
void in_3(bool val);
void in_4(bool val);

};


#endif
