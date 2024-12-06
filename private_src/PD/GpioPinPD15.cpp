#include "GpioPinPD15.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPD15::Port()
{
    return GPIOD;
}

uint32_t bsp::GpioPinPD15::Pin()
{
    return GPIO_PIN_15;
}

std::string bsp::GpioPinPD15::PinName() const
{
    return "PD15";
}
