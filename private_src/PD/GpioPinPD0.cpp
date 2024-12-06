#include "GpioPinPD0.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPD0::Port()
{
    return GPIOD;
}

uint32_t bsp::GpioPinPD0::Pin()
{
    return GPIO_PIN_0;
}

std::string bsp::GpioPinPD0::PinName() const
{
    return "PD0";
}
