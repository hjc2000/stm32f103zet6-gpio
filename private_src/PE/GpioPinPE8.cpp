#include "GpioPinPE8.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE8::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE8::Pin()
{
    return GPIO_PIN_8;
}

std::string bsp::GpioPinPE8::PinName() const
{
    return "PE8";
}
