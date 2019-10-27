#pragma once

#include "AMonitorDisplay.hpp"

#define DISPLAY_COUT_TITLE_START "\e[1m"  // start for title lines
#define DISPLAY_COUT_TITLE_END ":\x1B[0m"  // end for title lines
#define DISPLAY_COUT_CONTENT_START " -> "  // start for normal lines
#define DISPLAY_COUT_CONTENT_END ""  // end for normal lines

class CoutMonitorDisplay : public AMonitorDisplay {
    public:
        CoutMonitorDisplay();
        CoutMonitorDisplay(CoutMonitorDisplay const &src);
        virtual ~CoutMonitorDisplay();

        CoutMonitorDisplay      &operator=(CoutMonitorDisplay const &rhs);
        virtual bool            init(uint32_t w, uint32_t h);
        virtual bool            beforeDisplay();
        virtual bool            afterDisplay();
        virtual void            coutTitle(const std::string &src) const;
        virtual void            coutContent(const std::string &src) const;
        virtual bool            baseDisplay(AMonitorModule *amodule, uint32_t index, uint32_t nbLines);
        virtual bool            display(ATitleMonitorModule *module, size_t index, size_t length);
        virtual bool            display(AAttributeListMonitorModule *module, size_t index, size_t length);

        virtual bool        isUnderScreen(size_t sz) const;
        virtual bool        isUpperScreen() const;
    protected:
    private:
};
