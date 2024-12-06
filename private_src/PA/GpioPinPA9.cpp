#include "GpioPinPA9.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPA9::Port()
{
    return GPIOA;
}

uint32_t bsp::GpioPinPA9::Pin()
{
    return GPIO_PIN_9;
}

std::string bsp::GpioPinPA9::PinName() const
{
    return "PA9";
}
