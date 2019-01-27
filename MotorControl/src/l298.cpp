#include "l298.h"
// Code for controlling H_BRIDGE_H
// todo: see if digital io is thread safe already. I think it is

// Constructor using Member Initializer List
l298::l298(PinName ENA, PinName ENB, PinName IN1, PinName IN2, PinName IN3, PinName IN4): ENA(ENA), ENB(ENB), IN1(IN1), IN2(IN2), IN3(IN3), IN4(IN4) {};

void l298::enable_a(bool val)
{
  //mu.lock();
  ENA.write(val);
  //mu.unlock();
}

void l298::in_1(bool val)
{
  //mu.lock();
  IN1.write(val);
  //mu.unlock();
}

void l298::in_2(bool val)
{
  //mu.lock();
  IN2.write(val);
  //mu.unlock();
}

void l298::in_3(bool val)
{
  //mu.lock();
  IN3.write(val);
  //mu.unlock();
}

void l298::in_4(bool val)
{
  //mu.lock();
  IN4.write(val);
  //mu.unlock();
}
