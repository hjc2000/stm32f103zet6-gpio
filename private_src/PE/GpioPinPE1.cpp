#include "GpioPinPE1.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE1::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE1::Pin()
{
    return GPIO_PIN_1;
}

std::string bsp::GpioPinPE1::PinName() const
{
    return "PE1";
}
