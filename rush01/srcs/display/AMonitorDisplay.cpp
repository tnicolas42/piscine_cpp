#include "AMonitorDisplay.hpp"

AMonitorDisplay::AMonitorDisplay() :
_isQuit(false) {
}

AMonitorDisplay::AMonitorDisplay(AMonitorDisplay const &src) {
    *this = src;
}

AMonitorDisplay::~AMonitorDisplay() {
}

AMonitorDisplay &AMonitorDisplay::operator=(AMonitorDisplay const &rhs) {
    if (this != &rhs) {
        _isQuit = rhs.isQuit();
        _width = rhs.getWidth();
        _height = rhs.getHeight();
    }
    return *this;
}

bool        AMonitorDisplay::init(uint32_t w, uint32_t h) {
    _width = w;
    _height = h;
    return true;
}

bool        AMonitorDisplay::display(AMonitorModule *amodule, size_t index, size_t length) {
    if (amodule->getType() == "TitleMonitorModule")
        display(static_cast<ATitleMonitorModule*>(amodule), index, length);
    else if (amodule->getType() == "AttributeListMonitorModule")
        display(static_cast<AAttributeListMonitorModule*>(amodule), index, length);
    else {
        std::cerr << "Invalid type to display module: " << amodule->getType() << std::endl;
        return false;
    }
    return true;
}

bool        AMonitorDisplay::isQuit() const { return _isQuit; }
uint32_t    AMonitorDisplay::getWidth() const { return _width; }
uint32_t    AMonitorDisplay::getHeight() const { return _height; }