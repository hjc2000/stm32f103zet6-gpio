#pragma once
#include <bsp-interface/di/gpio.h>
#include <bsp-interface/di/interrupt.h>
#include <hal.h>

namespace bsp
{
    class GpioPin :
        public bsp::IGpioPin
    {
    protected:
        bool _is_open = false;

    public:
        virtual ~GpioPin() = default;

        virtual GPIO_TypeDef *Port() = 0;
        virtual uint32_t Pin() = 0;

        /// @brief 指示此引脚是否已经打开。
        /// @return
        bool IsOpen() override
        {
            return _is_open;
        }

        /// @brief 将引脚打开为输入模式。
        /// @param pull_mode 拉模式。可以选择上拉、下拉、不拉。
        /// @param trigger_edge 中断触发边沿。
        virtual void OpenAsInputMode(bsp::IGpioPinPullMode pull_mode, bsp::IGpioPinTriggerEdge trigger_edge) override;

        /// @brief 将引脚打开为输出模式。
        /// @param pull_mode 拉模式。
        /// @param driver_mode 驱动模式。
        virtual void OpenAsOutputMode(bsp::IGpioPinPullMode pull_mode, bsp::IGpioPinDriver driver_mode) override;

        /// @brief 将引脚打开为复用功能。
        /// @param function_name 复用功能名称。
        /// @param pull_mode 拉模式。
        /// @param driver_mode 驱动模式。
        virtual void OpenAsAlternateFunctionMode(std::string function_name,
                                                 bsp::IGpioPinPullMode pull_mode,
                                                 bsp::IGpioPinDriver driver_mode);

        void Close() override;

        /// @brief 使能时钟
        void EnableClock();

        bool ReadPin() override;
        void WritePin(bool value) override;
        void TogglePin() override;

        /// @brief 设置中断回调函数。
        /// @warning 只有当前引脚处于关闭状态才能设置。
        /// @param callback
        void RegisterInterruptCallback(std::function<void()> callback) override;

        /// @brief 取消注册此引脚的中断回调函数。
        void UnregisterInterruptCallback() override;
    };
} // namespace bsp
