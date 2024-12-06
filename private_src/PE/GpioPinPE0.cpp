#include "GpioPinPE0.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE0::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE0::Pin()
{
    return GPIO_PIN_0;
}

std::string bsp::GpioPinPE0::PinName() const
{
    return "PE0";
}
