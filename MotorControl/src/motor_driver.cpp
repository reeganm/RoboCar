#include "motor_driver.h"
// Class for controlling a L298 motor driver

// Constructor using Member Initializer List
motor_driver::motor_driver(PinName EN, PinName IN1, PinName IN2): EN(EN), IN1(IN1), IN2(IN2)
{
  set_period();
};

// set pwm period
void motor_driver::set_period(void)
{
  EN.period(0.1f);
}

// enable motor driver
void motor_driver::set_speed(float speed)
{
  EN.write(speed);
}

void motor_driver::set_polarity(bool pol)
{
  polarity = pol;
}

void motor_driver::forward(void)
{
  mu.lock();
  if (polarity)
  {
    IN1.write(false);
    IN2.write(true);
  }
  else
  {
    IN2.write(false);
    IN1.write(true);
  }
  mu.unlock();
}

void motor_driver::backward(void)
{
  mu.lock();
  if (polarity)
  {
    IN2.write(false);
    IN1.write(true);
  }
  else
  {
    IN1.write(false);
    IN2.write(true);
  }
  mu.unlock();
}

// active braking
void motor_driver::hard_stop(void)
{
  mu.lock();
  IN1.write(false);
  IN2.write(false);
  mu.unlock();
}
