/*
 * This example is showing how to use the softpwm lib.
 * I use a fullcolor led, which each pin is inited as
 * pwm output. Finally, the result of this example is
 * three color from dark to light to dark by degrees,
 * and one by one.
 */
#include <wiringPi.h>
#include <stdio.h>
#include <thread>
#include <list>

#include "pwm.h"

int main (void)
{
  printf ("SoftPWM test\n") ;
  wiringPiSetup();

  std::list<PWM*> ledList;
  const int pwmRange = 1000;

  auto addLED = [&](GPIOPin pin){
      auto led = new PWM(pin, pwmRange);
      led->update(pwmRange);    //ensure led is off
      ledList.push_back(led);

      return led;
  };

  // from range --> 0 --> range
  auto runLED = [&](PWM* led){
      for(int value = 0; value < pwmRange; value++){
          led->update(pwmRange - value);
          std::this_thread::sleep_for(std::chrono::milliseconds(1));
      }
      for(int value = 0; value < pwmRange; value++){
          led->update(value);
          std::this_thread::sleep_for(std::chrono::milliseconds(1));
      }
  };

  addLED(GPIOPin::GPIOA12);
  addLED(GPIOPin::GPIOG11);
  addLED(GPIOPin::GPIOA11);
  for(;;){
      for(auto led : ledList){
          runLED(led);
      }
  }

//  // ofcause cannot get here
//  for(auto led : ledList){
//      delete led;
//  }

  return 0;
}
