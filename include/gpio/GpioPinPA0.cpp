#include "GpioPinPA0.h"
#include <gpio/GpioPinOptions.h>
#include <hal.h>

GPIO_TypeDef *bsp::GpioPinPA0::Port()
{
	return GPIOA;
}

uint32_t bsp::GpioPinPA0::Pin()
{
	return GPIO_PIN_0;
}

void bsp::GpioPinPA0::Open(bsp::IGpioPinOptions const &options)
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

void bsp::GpioPinPA0::Close()
{
	if (!_is_open)
	{
		return;
	}

	_is_open = false;
}
