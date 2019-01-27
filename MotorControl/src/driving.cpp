// Thread for controlling driving of car

#include "driving.h"

#include "pin_def.h"
#include "motor_driver.h"

#include "mail_box.h"

motor_driver flm(ENFL, IN1FL, IN2FL);
motor_driver frm(ENFR, IN1FR, IN2FR);
motor_driver blm(ENBL, IN1BL, IN2BL);
motor_driver brm(ENBR, IN1BR, IN2BR);

void driving_thread(void)
{
  while(1)
  {
    osEvent evt = mail_box.get();
    if (evt.status == osEventMail)
    {
      mail_t *mail = (mail_t*)evt.value.p;
      mail_box.free(mail);
    }
    wait(0.05f);
  }
}
