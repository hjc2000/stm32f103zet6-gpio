#include "GpioPinPD10.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPD10::Port()
{
    return GPIOD;
}

uint32_t bsp::GpioPinPD10::Pin()
{
    return GPIO_PIN_10;
}

std::string bsp::GpioPinPD10::PinName() const
{
    return "PD10";
}
