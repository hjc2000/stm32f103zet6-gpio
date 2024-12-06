#include "GpioPinPD14.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPD14::Port()
{
    return GPIOD;
}

uint32_t bsp::GpioPinPD14::Pin()
{
    return GPIO_PIN_14;
}

std::string bsp::GpioPinPD14::PinName() const
{
    return "PD14";
}
