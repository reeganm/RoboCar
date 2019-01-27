#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <mbed.h>

class motor_driver {

private:
  Mutex mu;

  PwmOut EN;
  void set_period(void);

  DigitalOut IN1;
  DigitalOut IN2;

  bool polarity = 1; //for flipping polarity of motor without rewiring

public:
  // Constructor
  motor_driver(PinName EN, PinName IN1, PinName IN2);

  // Methods

  // sets speed and also braking pwr
  void set_speed(float speed);

  // for flipping motor polarity
  void set_polarity(bool pol);

  // drives motor forwards
  void forward(void);

  // drives motor in reverse
  void backward(void);

  // active breaking maximum when speed = 1
  void hard_stop(void);

};

#endif
