#include "GpioPinPE10.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE10::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE10::Pin()
{
    return GPIO_PIN_10;
}

std::string bsp::GpioPinPE10::PinName() const
{
    return "PE10";
}
