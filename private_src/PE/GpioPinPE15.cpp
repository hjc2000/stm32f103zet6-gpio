#include "GpioPinPE15.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE15::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE15::Pin()
{
    return GPIO_PIN_15;
}

std::string bsp::GpioPinPE15::PinName() const
{
    return "PE15";
}
