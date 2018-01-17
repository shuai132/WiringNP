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

void GPIO::setMode(const GPIOMode &mode)
{
    pinMode((int)_pin, (int)mode);
}

GPIOMode GPIO::getMode()
{
    return _mode;
}

void GPIO::setValue(int value)
{
    _value = value;
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

void GPIO::high()
{
    setValue(HIGH);
}

void GPIO::low()
{
    setValue(LOW);
}

void GPIO::toggle()
{
    if(_value == HIGH)
        setValue(LOW);
    else
        setValue(HIGH);
}

GPIO &GPIO::operator=(int value)
{
    setValue(value);
    return *this;
}

GPIO &GPIO::operator=(GPIO &io)
{
    setValue(io.getValue());
    return *this;
}

GPIO::GPIO(const GPIOPin &pin, const EDGEMode &mode, EdgeCallback callback)
    :_pin(pin)
{
    _mode = GPIOMode::Input;
    pinMode((int)_pin, (int)_mode);
    wiringPiISR((int)_pin, (int)mode, callback);
}

void GPIO::setEdgeCallback(GPIO::EdgeCallback callback)
{
    wiringPiISR ((int)_pin, (int)_mode, callback) ;
}
