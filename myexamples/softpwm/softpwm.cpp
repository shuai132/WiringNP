
#include <stdio.h>
#include <wiringPi.h>

#include "pwm.h"

int main (void)
{
  printf ("SoftPWM test\n") ;
  wiringPiSetup();

  auto ledPWM = PWM(GPIOPin::GPIOA12, 500, 1000);

  for(;;){
      for(int value = 0; value < 1000; value++){
          ledPWM.write(value);
          delay(1);
      }

      for(int value = 0; value < 10000; value++){
          ledPWM.write(1000 - value);
          delay(1);
      }
  }

  return 0;
}
