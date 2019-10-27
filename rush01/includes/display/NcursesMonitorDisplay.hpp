#pragma once

#include "AMonitorDisplay.hpp"
#include <ncurses.h>

#define DISPLAY_NCURSES_MIN_WIDTH 50
#define DISPLAY_NCURSES_MIN_HEIGHT 10
#define DISPLAY_NCURSES_MAX_WIDTH 2000
#define DISPLAY_NCURSES_MAX_HEIGHT 2000

#define DISPLAY_NCURSES_INDENT_TITLE 2
#define DISPLAY_NCURSES_INDENT_CONTENT 4
#define DISPLAY_NCURSES_SCROLL_SPEED 1

class NcursesMonitorDisplay : public AMonitorDisplay {
    public:
        NcursesMonitorDisplay();
        NcursesMonitorDisplay(NcursesMonitorDisplay const &src);
        virtual ~NcursesMonitorDisplay();

        NcursesMonitorDisplay      &operator=(NcursesMonitorDisplay const &rhs);
        virtual bool            checkSize();
        virtual bool            init(uint32_t w, uint32_t h);
        void                    scroll_(int val);
        virtual bool            event();
        virtual void            redrawWin();
        virtual bool            beforeDisplay();
        virtual bool            afterDisplay();
        virtual bool            baseDisplay(AMonitorModule *amodule, uint32_t index, uint32_t nbLines);
        const char              *getLineStr(std::string const &src);
        virtual bool            display(ATitleMonitorModule *module, size_t index, size_t length);
        virtual bool            display(AAttributeListMonitorModule *module, size_t index, size_t length);

        virtual bool        isUnderScreen(size_t sz) const;
        virtual bool        isUpperScreen() const;
    protected:
    private:
        std::vector<WINDOW*>    _boxInfo;
        float                   _lastY;  // last module y position
        float                   _scrollY;  // scroll value
        float                   _heightContent;  // height of the content
};
