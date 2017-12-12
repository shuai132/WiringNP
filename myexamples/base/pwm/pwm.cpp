#include "pwm.h"

#include <softPwm.h>

PWM::PWM(GPIOPin pin, int value, int range)
    :_pin(pin), _value(value), _range(range)
{
    softPwmCreate((int)_pin, value, range);
}

PWM::write(int value)
{
    softPwmWrite((int)_pin, value);
}

PWM::stop()
{
    softPwmStop((int)_pin);
}

int PWM::getValue()
{
    return _value;
}

int PWM::getRange()
{
    return _range;
}

double PWM::getPercent()
{
    return _value / _range;
}
