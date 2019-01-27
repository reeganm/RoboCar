#include <mbed.h>

#include "pin_def.h"
#include "driving.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

Thread led_t;

void led_thread(void)
{
  led1 = 1;
  while(true)
  {
    led1 = !led1;
    led2 = !led2;
  }
}

Thread driving_t;


int main()
{
  //start led thread
  led_t.start(led_thread);

  //start driving thread
  driving_t.start(driving_thread);

  //rtc setup
  set_time(1256729737);

  while(1)
  {
    wait(1);
  }
}
