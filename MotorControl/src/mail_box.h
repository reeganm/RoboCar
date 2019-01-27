#ifndef MAIL_BOX_H
#define MAIL_BOX_H

#include <mbed.h>

typedef struct {
  int MessageType;
  int data;
} mail_t;

extern Mail<mail_t, 16> mail_box;

#endif
