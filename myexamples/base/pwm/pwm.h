#ifndef PWM_H
#define PWM_H

#include "iotypes.h"

#include "gpio.h"
#include <thread>

class PWM
{
public:
    explicit PWM(const GPIOPin &pin, const int range = 100, const int freq = 100, const int value = 0);
    ~PWM();

    void update(const int &value);

    int getValue();
    int getRange();
    double getPercent();

private:
    static const long _MaxFreq = 1000000L;
    volatile int _highLevelTime;    //us
    volatile int _lowLevelTime;     //us

    // IO
    GPIO *_io;
    GPIOPin _pin;
    int _range;
    int _freq;
    int _value;

    // thread
    std::thread *_thread;
    volatile bool _threadRunning = false;
};

#endif // PWM_H
