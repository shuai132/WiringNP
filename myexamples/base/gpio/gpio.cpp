#include "gpio.h"

#include <wiringPi.h>
#include <assert.h>

GPIO::GPIO(const GPIOPin &pin, const GPIOMode &mode, const int value)
    :_pin(pin), _mode(mode), _value(value)
{
    assert(mode == INPUT or mode == OUTPUT);    //only support input and output mode now

    pullUpDnControl((int)pin, PUD_OFF);
    pinMode((int)pin, mode);

    if(mode == OUTPUT){
        digitalWrite((int)pin, value);
    }
}

void GPIO::high()
{
    _value = HIGH;
    digitalWrite((int)_pin, _value);
}

void GPIO::low()
{
    _value = LOW;
    digitalWrite((int)_pin, _value);
}

void GPIO::toggle()
{
    if(_value == HIGH)
        _value = LOW;
    else
        _value = HIGH;

    digitalWrite((int)_pin, _value);
}

int GPIO::getValue()
{
    if(_mode == OUTPUT){
        return _value;
    }
    else {
        return digitalRead((int)_pin);
    }
}

void GPIO::setMode(const GPIOMode &mode)
{
    pinMode((int)_pin, mode);
}

GPIOMode GPIO::getMode()
{
    return _mode;
}
