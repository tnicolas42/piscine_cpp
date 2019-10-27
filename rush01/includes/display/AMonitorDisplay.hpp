#pragma once

#include "IMonitorDisplay.hpp"
#include "ATitleMonitorModule.hpp"
#include "AAttributeListMonitorModule.hpp"

class AMonitorDisplay : public IMonitorDisplay {
    public:
        AMonitorDisplay();
        AMonitorDisplay(AMonitorDisplay const &src);
        virtual ~AMonitorDisplay();

        AMonitorDisplay &operator=(AMonitorDisplay const &rhs);

        virtual bool        init(uint32_t w, uint32_t h);
        virtual bool        beforeDisplay() = 0;
        virtual bool        afterDisplay() = 0;
        virtual bool        display(ATitleMonitorModule *module, size_t index, size_t length) = 0;
        virtual bool        display(AAttributeListMonitorModule *module, size_t index, size_t length) = 0;
        virtual bool        display(AMonitorModule *amodule, size_t index, size_t length);
        virtual bool        isQuit() const;
        virtual bool        isUnderScreen(size_t sz) const = 0;
        virtual bool        isUpperScreen() const = 0;
        virtual uint32_t    getWidth() const;
        virtual uint32_t    getHeight() const;
    protected:
        uint32_t    _width;
        uint32_t    _height;
        bool        _isQuit;
    private:
};
