
#include <stdio.h>
#include <wiringPi.h>

#include "gpio.h"

int main (void)
{
  printf ("Button callback test\n") ;
  wiringPiSetup();

  auto led_r = GPIO(GPIOPin::GPIOA12, GPIOMode::Output);

//  ISR NOT SUPPORT NOW IN WIRINGPI
//  auto button = GPIO(GPIOPin::GPIOA6, EDGEMode::Falling, [](){
//      printf("you clicked button~");
//  });

  for(;;){
      led_r.toggle();
      delay(500);
  }

  return 0;
}
