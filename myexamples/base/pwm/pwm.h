#ifndef PWM_H
#define PWM_H

#include "iotypes.h"

class PWM
{
public:
    PWM(GPIOPin pin, int value, int range);

    void write(int value);
    void stop();

    int getValue();
    int getRange();
    double getPercent();

private:
    GPIOPin _pin;
    int _range;
    int _value;
};

#endif // PWM_H
