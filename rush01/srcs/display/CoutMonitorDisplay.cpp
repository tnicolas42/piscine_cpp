#include "CoutMonitorDisplay.hpp"
#include <iostream>
#include <sys/ioctl.h>

CoutMonitorDisplay::CoutMonitorDisplay() :
AMonitorDisplay() {
}

CoutMonitorDisplay::CoutMonitorDisplay(CoutMonitorDisplay const &src) :
AMonitorDisplay(src) {
    *this = src;
}

CoutMonitorDisplay::~CoutMonitorDisplay() {
}

CoutMonitorDisplay &CoutMonitorDisplay::operator=(CoutMonitorDisplay const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

bool        CoutMonitorDisplay::init(uint32_t w, uint32_t h) {
    (void)w;
    (void)h;
    return true;
}

bool        CoutMonitorDisplay::beforeDisplay() {
    return true;
}

bool        CoutMonitorDisplay::afterDisplay() {
    _isQuit = true;
    return true;
}

bool CoutMonitorDisplay::baseDisplay(AMonitorModule *amodule, uint32_t index, uint32_t nbLines) {
    (void)index;
    (void)nbLines;
    coutTitle(amodule->getName());
    return true;
}

bool        CoutMonitorDisplay::display(ATitleMonitorModule *module, size_t index, size_t length) {
    (void)length;
    // draw rectangle and name
    if (baseDisplay(module, index, 1) == false) {  // display for 1 lines
        return false;
    }

    coutContent(module->getValue());

    return true;
}

bool        CoutMonitorDisplay::display(AAttributeListMonitorModule *module, size_t index, size_t length) {
    (void)length;
    std::vector<Attribute> const attr = module->getAttributes();

    // draw rectangle and name
    if (baseDisplay(module, index, attr.size()) == false) {  // display for 1 lines
        return false;
    }

    for (uint32_t i=0; i < attr.size(); i++) {
        std::string str = attr[i].getName() + ": " + attr[i].getValue();
        coutContent(str);
    }

    return true;
}


void CoutMonitorDisplay::coutTitle(const std::string &src) const {
    std::cout << DISPLAY_COUT_TITLE_START << src << DISPLAY_COUT_TITLE_END << std::endl;
}
void CoutMonitorDisplay::coutContent(const std::string &src) const {
    std::cout << DISPLAY_COUT_CONTENT_START << src << DISPLAY_COUT_CONTENT_END << std::endl;
}

bool        CoutMonitorDisplay::isUnderScreen(size_t sz) const {
    (void)sz;
    return false;
}
bool        CoutMonitorDisplay::isUpperScreen() const {
    return false;
}
