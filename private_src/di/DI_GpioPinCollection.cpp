#include <base/container/Collection.h>
#include <base/Initializer.h>
#include <GpioPinOptions.h>
#include <pins.h>

static base::Initializer _initializer{
    []()
    {
        DI_GpioPinCollection();
    }};

class Initializer
{
public:
    Initializer()
    {
#pragma region PA
        AddPin(bsp::GpioPinPA0::Instance());
        AddPin(bsp::GpioPinPA9::Instance());
        AddPin(bsp::GpioPinPA10::Instance());
#pragma endregion

#pragma region PB
        AddPin(bsp::GpioPinPB0::Instance());
        AddPin(bsp::GpioPinPB5::Instance());
#pragma endregion

#pragma region PD
        AddPin(bsp::GpioPinPD0::Instance());
        AddPin(bsp::GpioPinPD1::Instance());
        AddPin(bsp::GpioPinPD4::Instance());
        AddPin(bsp::GpioPinPD5::Instance());
        AddPin(bsp::GpioPinPD8::Instance());
        AddPin(bsp::GpioPinPD9::Instance());
        AddPin(bsp::GpioPinPD10::Instance());
        AddPin(bsp::GpioPinPD11::Instance());
        AddPin(bsp::GpioPinPD14::Instance());
        AddPin(bsp::GpioPinPD15::Instance());
#pragma endregion

#pragma region PE
        AddPin(bsp::GpioPinPE3::Instance());
        AddPin(bsp::GpioPinPE4::Instance());
        AddPin(bsp::GpioPinPE5::Instance());
        AddPin(bsp::GpioPinPE7::Instance());
        AddPin(bsp::GpioPinPE8::Instance());
        AddPin(bsp::GpioPinPE9::Instance());
        AddPin(bsp::GpioPinPE10::Instance());
        AddPin(bsp::GpioPinPE11::Instance());
        AddPin(bsp::GpioPinPE12::Instance());
        AddPin(bsp::GpioPinPE13::Instance());
        AddPin(bsp::GpioPinPE14::Instance());
        AddPin(bsp::GpioPinPE15::Instance());
#pragma endregion

#pragma region PG
        AddPin(bsp::GpioPinPG0::Instance());
        AddPin(bsp::GpioPinPG12::Instance());
#pragma endregion
    }

    void AddPin(bsp::IGpioPin &pin)
    {
        _collection.Put(pin.PinName(), &pin);
    }

    base::Collection<std::string, bsp::IGpioPin *> _collection{};
};

base::ICollection<std::string, bsp::IGpioPin *> &DI_GpioPinCollection()
{
    static Initializer o;
    return o._collection;
}
