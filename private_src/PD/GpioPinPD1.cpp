#include "GpioPinPD1.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPD1::Port()
{
    return GPIOD;
}

uint32_t bsp::GpioPinPD1::Pin()
{
    return GPIO_PIN_1;
}

std::string bsp::GpioPinPD1::PinName() const
{
    return "PD1";
}
