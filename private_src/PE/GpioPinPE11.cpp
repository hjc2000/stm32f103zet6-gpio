#include "GpioPinPE11.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE11::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE11::Pin()
{
    return GPIO_PIN_11;
}

std::string bsp::GpioPinPE11::PinName() const
{
    return "PE11";
}
