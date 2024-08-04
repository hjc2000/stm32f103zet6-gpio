#include "GpioPinPE5.h"
#include <base/Initializer.h>
#include <gpio/GpioPinOptions.h>
#include <hal.h>

static base::Initializer _init{
	[]()
	{
		bsp::GpioPinPE5::Instance();
	}};

GPIO_TypeDef *bsp::GpioPinPE5::Port()
{
	return GPIOE;
}

uint32_t bsp::GpioPinPE5::Pin()
{
	return GPIO_PIN_5;
}

void bsp::GpioPinPE5::Open(bsp::IGpioPinOptions const &options)
{
	if (_is_open)
	{
		return;
	}

	_is_open = true;

	__HAL_RCC_GPIOE_CLK_ENABLE();
	GPIO_InitTypeDef init = static_cast<bsp::GpioPinOptions const &>(options);
	init.Pin = Pin();
	HAL_GPIO_Init(Port(), &init);
}

void bsp::GpioPinPE5::Close()
{
	if (!_is_open)
	{
		return;
	}

	_is_open = false;
}
