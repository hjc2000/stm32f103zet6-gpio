#include "GpioPinPA9.h"
#include <base/Initializer.h>
#include <gpio/GpioPinOptions.h>
#include <hal.h>

static base::Initializer _init{
	[]()
	{
		bsp::GpioPinPA9::Instance();
	}};

GPIO_TypeDef *bsp::GpioPinPA9::Port()
{
	return GPIOA;
}

uint32_t bsp::GpioPinPA9::Pin()
{
	return GPIO_PIN_9;
}

void bsp::GpioPinPA9::Open(bsp::IGpioPinOptions const &options)
{
	if (_is_open)
	{
		return;
	}

	_is_open = true;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef init = static_cast<bsp::GpioPinOptions const &>(options);
	init.Pin = Pin();
	HAL_GPIO_Init(Port(), &init);
}

void bsp::GpioPinPA9::Close()
{
	if (!_is_open)
	{
		return;
	}

	_is_open = false;
}
