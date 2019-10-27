#pragma once

#include <stdlib.h>
#include "AMonitorModule.hpp"

class IMonitorDisplay {
    public:
        virtual bool        init(uint32_t w, uint32_t h) = 0;
        virtual bool        beforeDisplay() = 0;
        virtual bool        afterDisplay() = 0;
        virtual bool        display(AMonitorModule 	*amodule, size_t index, size_t length) = 0;

        virtual bool        isQuit() const = 0;
        virtual uint32_t    getWidth() const = 0;
        virtual uint32_t    getHeight() const = 0;
    protected:
    private:
};
