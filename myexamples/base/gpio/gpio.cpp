#include "gpio.h"

#include <wiringPi.h>
#include <assert.h>

GPIO::GPIO(const GPIOPin &pin, const GPIOMode &mode)
    :_pin(pin), _mode(mode)
{
    assert((int)mode == INPUT or (int)mode == OUTPUT);

    pullUpDnControl((int)pin, PUD_OFF);
    pinMode((int)pin, (int)mode);

    if((int)mode == OUTPUT){
        _value = HIGH;
        digitalWrite((int)pin, _value);
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
    if(_mode == GPIOMode::Output){
        return _value;
    }
    else {
        return digitalRead((int)_pin);
    }
}

GPIO::GPIO(const GPIOPin &pin, const EDGEMode &mode, GPIO::EdgeCallback callback)
    :_pin(pin), _callback(callback)
{
    _mode = GPIOMode::Input;
    pinMode((int)_pin, (int)_mode);
    wiringPiISR((int)_pin, (int)mode, callback);
}

void GPIO::setEdgeCallback(GPIO::EdgeCallback callback)
{
    wiringPiISR ((int)_pin, (int)_mode, callback) ;
}

void GPIO::setMode(const GPIOMode &mode)
{
    pinMode((int)_pin, (int)mode);
}

GPIOMode GPIO::getMode()
{
    return _mode;
}
