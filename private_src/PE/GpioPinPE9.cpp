#include "GpioPinPE9.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE9::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE9::Pin()
{
    return GPIO_PIN_9;
}

std::string bsp::GpioPinPE9::PinName() const
{
    return "PE9";
}
