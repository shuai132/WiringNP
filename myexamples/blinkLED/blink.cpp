
#include <stdio.h>
#include <wiringPi.h>
#include <random>

#include "gpio.h"

static void randomLed(GPIO &led){
    static std::random_device rd;
    if(rd() % 2 == 0) {
        led.high();
    } else {
        led.low();
    }
}

int main (void)
{
  printf ("Three color led test\n") ;
  wiringPiSetup();

  auto led_r = GPIO(GPIOPin::GPIOA12, GPIOMode::Output);
  auto led_g = GPIO(GPIOPin::GPIOG11, GPIOMode::Output);
  auto led_b = GPIO(GPIOPin::GPIOA11, GPIOMode::Output);

  for(;;){
      randomLed(led_r);
      randomLed(led_g);
      randomLed(led_b);
      delay(500);
  }

  return 0;
}
