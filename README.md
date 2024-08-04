# stm32f103-gpio

# 单例初始化

本库中的每一个 GPIO 引脚类都是单例，即有类似如下的静态方法

```cpp
static GpioPinPA0 &Instance()
{
    static GpioPinPA0 o;
    return o;
}
```

本来单例应该要使用 `base::Initializer` 类来注册到初始化列表中，但是，一旦这么做，就会导致每一个 GPIO 引脚类都被用到，会导致代码段特别大。所以本库不这么做。用户需要保证自己用到的引脚被 `base::Initializer` 直接或间接初始化。

# 间接被  `base::Initializer`  初始化的例子

实现 `DI_GpioPinCollection` 函数

```cpp
std::shared_ptr<bsp::IGpioPinOptions> DICreate_GpioPinOptions()
{
	return std::shared_ptr<bsp::IGpioPinOptions>{new bsp::GpioPinOptions{}};
}

base::IReadOnlyCollection<std::string, bsp::IGpioPin *> &DI_GpioPinCollection()
{
	class Collection
		: public base::IReadOnlyCollection<std::string, bsp::IGpioPin *>
	{
	private:
		std::map<std::string, bsp::IGpioPin *> _pin_map{
			{bsp::GpioPinPA0::Instance().PinName(), &bsp::GpioPinPA0::Instance()},
			{bsp::GpioPinPA9::Instance().PinName(), &bsp::GpioPinPA9::Instance()},
			{bsp::GpioPinPA10::Instance().PinName(), &bsp::GpioPinPA10::Instance()},
			{bsp::GpioPinPB5::Instance().PinName(), &bsp::GpioPinPB5::Instance()},
			{bsp::GpioPinPE3::Instance().PinName(), &bsp::GpioPinPE3::Instance()},
			{bsp::GpioPinPE4::Instance().PinName(), &bsp::GpioPinPE4::Instance()},
			{bsp::GpioPinPE5::Instance().PinName(), &bsp::GpioPinPE5::Instance()},
		};

	public:
		int Count() const override
		{
			return _pin_map.size();
		}

		bsp::IGpioPin *Get(std::string key) const override
		{
			auto it = _pin_map.find(key);
			if (it == _pin_map.end())
			{
				return nullptr;
			}

			return it->second;
		}
	};

	static Collection o;
	return o;
}
```

此函数被第一次调用时会实例化一个局部 `Collection` 类的 static 对象，在 `Collection` 的构造函数中，所有 GPIO 引脚类单例都会被初始化。



然后将此函数注册到初始化列表：

```cpp
static base::Initializer _initializer{
	[]()
	{
		DI_GpioPinCollection();
	}};
```

这样就能保证被用到的 GPIO 类单例都能被初始化。