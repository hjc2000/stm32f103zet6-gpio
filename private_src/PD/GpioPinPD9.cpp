#include "GpioPinPD9.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPD9::Port()
{
    return GPIOD;
}

uint32_t bsp::GpioPinPD9::Pin()
{
    return GPIO_PIN_9;
}

std::string bsp::GpioPinPD9::PinName() const
{
    return "PD9";
}
