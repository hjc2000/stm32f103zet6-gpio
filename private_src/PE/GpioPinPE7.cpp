#include "GpioPinPE7.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE7::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE7::Pin()
{
    return GPIO_PIN_7;
}

std::string bsp::GpioPinPE7::PinName() const
{
    return "PE7";
}
