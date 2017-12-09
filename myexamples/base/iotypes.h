#ifndef IOTYPES_H
#define IOTYPES_H

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

typedef int GPIOMode;

#endif // IOTYPES_H
