#ifndef GPIO_H
#define GPIO_H

#include "iotypes.h"

#include <wiringPi.h>
#include <functional>

class GPIO
{
    typedef void (*EdgeCallback)(void);
public:
    GPIO(const GPIOPin &pin, const GPIOMode &mode);

    void setMode(const GPIOMode &mode);
    GPIOMode getMode();

    void setValue(int value);
    int  getValue();

    void high();
    void low();
    void toggle();

    GPIO& operator= (int value);
    GPIO& operator= (GPIO& io);

    GPIO(const GPIOPin &pin, const EDGEMode &mode, EdgeCallback callback);
    void setEdgeCallback(EdgeCallback callback);

private:
    GPIOPin  _pin;
    GPIOMode _mode;
    int      _value;
};

#endif // GPIO_H
