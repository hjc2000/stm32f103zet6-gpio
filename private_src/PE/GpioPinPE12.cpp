#include "GpioPinPE12.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE12::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE12::Pin()
{
    return GPIO_PIN_12;
}

std::string bsp::GpioPinPE12::PinName() const
{
    return "PE12";
}
