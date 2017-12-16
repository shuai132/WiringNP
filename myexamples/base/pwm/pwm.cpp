#include "pwm.h"

#include <cassert>
#include <thread>
#include <pthread.h>
#include <signal.h>

PWM::PWM(const GPIOPin &pin, const int range, const int freq, const int value)
    :_pin(pin), _range(range), _freq(freq), _value(value)
{
    assert(value <= range);

    update(value);

    _io = new GPIO(pin, GPIOMode::Output);
    _thread = new std::thread([&](){
        _isRunning = true;

        // signal for terminal itself
        signal(SIGTERM, [](int sig){
            pthread_exit(NULL);
        });

        for(;;){
            _io->high();
            std::this_thread::sleep_for(std::chrono::microseconds(_highLevelTime));
            _io->low();
            std::this_thread::sleep_for(std::chrono::microseconds(_lowLevelTime));
        }
    });
}

PWM::~PWM()
{
    // ensure thread is running when kill it
    while(!_isRunning){
        std::chrono::milliseconds(1);
    }
    pthread_kill(_thread->native_handle(), SIGKILL);
    _thread->join();

    delete _thread;
    delete _io;
}

void PWM::update(const int &value)
{
    _value = value;

    if(_value > _range){
        _value = _range;
    }
    int periodUS   = (int)(_MaxFreq / _freq);   // int is fine
    _highLevelTime = periodUS * _value / _range;
    _lowLevelTime  = periodUS - _highLevelTime;
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

