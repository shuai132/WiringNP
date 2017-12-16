/*
 * Random all color
 */
#include <wiringPi.h>
#include <thread>
#include <list>
#include <random>

#include "pwm.h"

int main (void)
{
  wiringPiSetup();

  std::list<PWM*> ledList;
  const int pwmRange = 64;  //color deep(6bit)

  auto addLED = [&](GPIOPin pin){
      auto led = new PWM(pin, pwmRange);
      led->update(pwmRange);    //ensure led is off
      ledList.push_back(led);

      return led;
  };

  auto randomColor = [&](PWM* led){
      static std::random_device rd;

      led->update(rd() % pwmRange);
  };

  addLED(GPIOPin::GPIOA12);
  addLED(GPIOPin::GPIOG11);
  addLED(GPIOPin::GPIOA11);
  for(;;){
      for(auto led : ledList){
          randomColor(led);
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

//  // ofcause cannot get here
//  for(auto led : ledList){
//      delete led;
//  }

  return 0;
}
