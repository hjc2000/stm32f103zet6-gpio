#include <base/container/Dictionary.h>
#include <base/di/SingletonGetter.h>
#include <bsp-interface/di/interrupt.h>
#include <GpioPinOptions.h>
#include <pins.h>

class Initializer
{
private:
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
        _dic.Add(pin.PinName(), &pin);
    }

public:
    static Initializer &Instance()
    {
        class Getter : public base::SingletonGetter<Initializer>
        {
        public:
            std::unique_ptr<Initializer> Create() override
            {
                return std::unique_ptr<Initializer>{new Initializer{}};
            }

            void Lock() override
            {
                DI_InterruptSwitch().DisableGlobalInterrupt();
            }

            void Unlock() override
            {
                DI_InterruptSwitch().EnableGlobalInterrupt();
            }
        };

        Getter g;
        return g.Instance();
    }

    base::Dictionary<std::string, bsp::IGpioPin *> _dic{};
};

base::IDictionary<std::string, bsp::IGpioPin *> const &DI_GpioPinCollection()
{
    return Initializer::Instance()._dic;
}
