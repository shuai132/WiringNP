#ifndef GPIO_H
#define GPIO_H

#include "iotypes.h"

#include <wiringPi.h>

class GPIO
{
public:
    explicit GPIO(const GPIOPin &pin, const GPIOMode &mode, const int value = HIGH);

    void setMode(const GPIOMode &mode);
    GPIOMode getMode();

    void high();
    void low();
    void toggle();
    int  getValue();

private:
    GPIOPin  _pin;
    GPIOMode _mode;
    int      _value;
};

#endif // GPIO_H
