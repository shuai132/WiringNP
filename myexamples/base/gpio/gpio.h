#ifndef GPIO_H
#define GPIO_H

#include "iotypes.h"

#include <wiringPi.h>
#include <functional>

class GPIO
{
    typedef void (*EdgeCallback)(void);
public:
    explicit GPIO(const GPIOPin &pin, const GPIOMode &mode);

    void setMode(const GPIOMode &mode);
    GPIOMode getMode();

    void high();
    void low();
    void toggle();
    int  getValue();

    explicit GPIO(const GPIOPin &pin, const EDGEMode &mode, EdgeCallback callback);
    void setEdgeCallback(EdgeCallback callback);

private:
    GPIOPin  _pin;
    GPIOMode _mode;
    int      _value;

    EdgeCallback _callback;
};

#endif // GPIO_H
