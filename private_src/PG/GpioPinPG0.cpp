#include "GpioPinPG0.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPG0::Port()
{
    return GPIOG;
}

uint32_t bsp::GpioPinPG0::Pin()
{
    return GPIO_PIN_0;
}

std::string bsp::GpioPinPG0::PinName() const
{
    return "PG0";
}
