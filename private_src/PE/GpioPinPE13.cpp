#include "GpioPinPE13.h"
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPE13::Port()
{
    return GPIOE;
}

uint32_t bsp::GpioPinPE13::Pin()
{
    return GPIO_PIN_13;
}

std::string bsp::GpioPinPE13::PinName() const
{
    return "PE13";
}
