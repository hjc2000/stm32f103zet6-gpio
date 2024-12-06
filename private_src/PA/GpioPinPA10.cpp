#include "GpioPinPA10.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPA10::Port()
{
    return GPIOA;
}

uint32_t bsp::GpioPinPA10::Pin()
{
    return GPIO_PIN_10;
}

std::string bsp::GpioPinPA10::PinName() const
{
    return "PA10";
}
