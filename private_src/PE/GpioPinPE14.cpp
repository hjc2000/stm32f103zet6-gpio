#include "GpioPinPE14.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE14::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE14::Pin()
{
    return GPIO_PIN_14;
}

std::string bsp::GpioPinPE14::PinName() const
{
    return "PE14";
}
