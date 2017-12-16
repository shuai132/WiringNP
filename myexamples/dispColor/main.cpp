/*
 * Display color
 */
#include <wiringPi.h>
#include <thread>
#include <stdio.h>

#include "pwm.h"

int main (void)
{
  wiringPiSetup();

  const int pwmRange = 256;  //color deep

  PWM ledR(GPIOPin::GPIOA12, pwmRange);
  PWM ledG(GPIOPin::GPIOG11, pwmRange);
  PWM ledB(GPIOPin::GPIOA11, pwmRange);

  auto dispColor = [&](int r, int g, int b){
      printf("now color is: %d, %d, %d\n", r, g, b);
      ledR.update(pwmRange - r);
      ledG.update(pwmRange - g);
      ledB.update(pwmRange - b);
  };

  for(;;){
      int r, g, b;
      printf("please input the value of : r g b\n");
      scanf("%d %d %d", &r, &g, &b);
      dispColor(r, g, b);
  }

  return 0;
}
