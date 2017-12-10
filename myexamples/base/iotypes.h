#ifndef IOTYPES_H
#define IOTYPES_H

#include <wiringPi.h>

enum class GPIOPin
{
    GPIOA0  = 0,
    GPIOA1  = 6,
    GPIOA2  = 2,
    GPIOA3  = 3,
    GPIOA6  = 1,
    GPIOA11 = 9,
    GPIOA12 = 8,

    GPIOC0  = 12,
    GPIOC1  = 13,
    GPIOC2  = 14,
    GPIOC3  = 10,

    GPIOG6  = 15,
    GPIOG7  = 16,
    GPIOG8  = 4,
    GPIOG9  = 5,
    GPIOG11 = 7,
};

enum class GPIOMode
{
    Input   = INPUT,
    Output  = OUTPUT,
};

enum class EDGEMode
{
    Setup   = INT_EDGE_SETUP,
    Falling = INT_EDGE_FALLING,
    Rising  = INT_EDGE_RISING,
    Both    = INT_EDGE_BOTH,
};

#endif // IOTYPES_H
