#include "NcursesMonitorDisplay.hpp"
#include <iostream>

NcursesMonitorDisplay::NcursesMonitorDisplay() :
AMonitorDisplay(),
_boxInfo(),
_lastY(0),
_scrollY(0),
_heightContent(0) {
}

NcursesMonitorDisplay::NcursesMonitorDisplay(NcursesMonitorDisplay const &src) :
AMonitorDisplay(src) {
    *this = src;
}

NcursesMonitorDisplay::~NcursesMonitorDisplay() {
    std::vector<WINDOW*>::iterator it;
    for (it = _boxInfo.begin(); it != _boxInfo.end(); it++) {
        delwin(*it);
    }
    curs_set(1);
    endwin();
}

NcursesMonitorDisplay &NcursesMonitorDisplay::operator=(NcursesMonitorDisplay const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

bool        NcursesMonitorDisplay::checkSize() {
    if (_width < DISPLAY_NCURSES_MIN_WIDTH || _width > DISPLAY_NCURSES_MAX_WIDTH) {
        std::cerr << "invalid width (btw " << DISPLAY_NCURSES_MIN_WIDTH << " and "
            << DISPLAY_NCURSES_MAX_WIDTH << ") -> " << _width << std::endl;
        return false;
    }
    if (_height < DISPLAY_NCURSES_MIN_HEIGHT || _height > DISPLAY_NCURSES_MAX_HEIGHT) {
        std::cerr << "invalid height (btw " << DISPLAY_NCURSES_MIN_HEIGHT << " and "
            << DISPLAY_NCURSES_MAX_HEIGHT << ") -> " << _width << std::endl;
        return false;
    }
    return true;
}

bool        NcursesMonitorDisplay::init(uint32_t w, uint32_t h) {
    initscr();
    _width = COLS;
    _height = LINES;
    if (AMonitorDisplay::init(w, h) == false)
        return false;
    if (checkSize() == false) {
        return false;
    }

    bool res = true;
    res |= curs_set(0);
	res |= keypad(stdscr, true);
    res |= noecho();
	res |= nodelay(stdscr, true);
	res |= notimeout(stdscr, true);

    return res;
}

void        NcursesMonitorDisplay::scroll_(int val) {
    int last = _scrollY;
    if (_scrollY + val >= 0) {
        _scrollY = 0;
    }
    else {
        _scrollY += val;
    }
    if (last != _scrollY) {
        redrawWin();
    }
}

void        NcursesMonitorDisplay::redrawWin() {
    std::vector<WINDOW*>::iterator it;
    for (it = _boxInfo.begin(); it != _boxInfo.end(); it++) {
        delwin(*it);
    }
    _boxInfo.clear();  // reset the vector object
    erase();
}

bool        NcursesMonitorDisplay::event() {
    int ch;
    while (1) {
        if ((ch = getch()) == ERR) {
            break;
        }
        else {
            if (ch == 27 || ch == 113) {  // escape | Q
                _isQuit = true;
            }
            else if (ch == 258) {  // down
                scroll_(-DISPLAY_NCURSES_SCROLL_SPEED);
            }
            else if (ch == 259) {  // up
                scroll_(DISPLAY_NCURSES_SCROLL_SPEED);
            }
        }
    }
    if (static_cast<int>(_width) != COLS || static_cast<int>(_height) != LINES) {  // resize
        _width = COLS;
        _height = LINES;
        if (checkSize() == false) {
            _isQuit = true;
        }
        redrawWin();
    }
    return true;
}

bool        NcursesMonitorDisplay::beforeDisplay() {
    _lastY = 0;
    event();
    return true;
}

bool        NcursesMonitorDisplay::afterDisplay() {
    _heightContent = _lastY;
    std::vector<WINDOW*>::iterator it;
    for (it = _boxInfo.begin(); it != _boxInfo.end(); it++) {
        wrefresh(*it);
    }
    refresh();
    return true;
}

bool NcursesMonitorDisplay::baseDisplay(AMonitorModule *amodule, uint32_t index, uint32_t nbLines) {
    nbLines += 1;  // for the name

    int height = 2 + nbLines;
    if (_boxInfo.size() <= index) {
        _boxInfo.push_back(newwin(height, COLS, _lastY + _scrollY, 0));
    }
    if (_boxInfo.size() < index) {
        std::cerr << "unexpected error in base display" << std::endl;
        return false;
    }
    box(_boxInfo[index], ACS_VLINE, ACS_HLINE);
    mvwprintw(_boxInfo[index], 1, DISPLAY_NCURSES_INDENT_TITLE, amodule->getName().c_str());
    _lastY += height;
    return true;
}

const char *NcursesMonitorDisplay::getLineStr(std::string const &src) {
    uint32_t maxWidth = _width - 2 - DISPLAY_NCURSES_INDENT_CONTENT;
    if (src.size() <= maxWidth)
        return src.c_str();
    return std::string(src.substr(0, maxWidth - 4) + " ...").c_str();
}

bool        NcursesMonitorDisplay::display(ATitleMonitorModule *module, size_t index, size_t length) {
    (void)length;
    if (_lastY + _scrollY > _height)
        return false;
    // draw rectangle and name
    if (baseDisplay(module, index, 1) == false) {  // display for 1 lines
        return false;
    }

    mvwprintw(_boxInfo[index], 2, DISPLAY_NCURSES_INDENT_CONTENT, getLineStr(module->getValue()));

    return true;
}

bool        NcursesMonitorDisplay::display(AAttributeListMonitorModule *module, size_t index, size_t length) {
    (void)length;
    std::vector<Attribute> const attr = module->getAttributes();

    // draw rectangle and name
    if (baseDisplay(module, index, attr.size()) == false) {  // display for 1 lines
        return false;
    }

    for (uint32_t i=0; i < attr.size(); i++) {
        std::string str = attr[i].getName() + ": " + attr[i].getValue();
        mvwprintw(_boxInfo[index], i+2, DISPLAY_NCURSES_INDENT_CONTENT, getLineStr(str));
    }

    return true;
}

bool        NcursesMonitorDisplay::isUnderScreen(size_t sz) const {
    // if (_lastY + _scrollY + sz + 2 < 0)
    //     return true;
    (void)sz;
    return false;
}
bool        NcursesMonitorDisplay::isUpperScreen() const {
    if (_lastY + _scrollY > _height)
        return true;
    return false;
}