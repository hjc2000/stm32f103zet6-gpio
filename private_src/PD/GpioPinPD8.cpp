#include "GpioPinPD8.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPD8::Port()
{
    return GPIOD;
}

uint32_t bsp::GpioPinPD8::Pin()
{
    return GPIO_PIN_8;
}

std::string bsp::GpioPinPD8::PinName() const
{
    return "PD8";
}
