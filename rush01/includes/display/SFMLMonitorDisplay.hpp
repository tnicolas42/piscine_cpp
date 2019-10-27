#pragma once

#include "AMonitorDisplay.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define DISPLAY_SFML_MIN_WIDTH 400
#define DISPLAY_SFML_MIN_HEIGHT 400
#define DISPLAY_SFML_MAX_WIDTH 2600
#define DISPLAY_SFML_MAX_HEIGHT 1400

#define DISPLAY_SFML_FONT "font/open-sans/OpenSans-Regular.ttf"
#define DISPLAY_SFML_TITLE_SIZE_PERCENT 0.03  // title size
#define DISPLAY_SFML_TEXT_SIZE_PERCENT 0.02  // normal text sizes
#define DISPLAY_SFML_TEXT_PAD_PERCENT 0.02  // padding to indent text
#define DISPLAY_SFML_BORDER_SZ_PERCENT 0.003  // border size for the rectangles
#define DISPLAY_SFML_BORDER_PAD_PERCENT 0.03  // [%] padding for the rectangle
#define DISPLAY_SFML_LINE_HEIGHT_PERCENT 0.04  // height of a line in %
#define DISPLAY_SFML_SCROLL_UP_KEY_PERCENT 0.05  // scroll speed with keyboard

#define DISPLAY_SFML_MAX_CHAR_LINE 90  // display max x chars in a line

#define DISPLAY_SFML_COLOR_BG sf::Color(30, 30, 30)  // bg color
#define DISPLAY_SFML_COLOR_RECT sf::Color(255, 255, 255)  // rectangle color

class SFMLMonitorDisplay : public AMonitorDisplay {
    public:
        SFMLMonitorDisplay();
        SFMLMonitorDisplay(SFMLMonitorDisplay const &src);
        virtual ~SFMLMonitorDisplay();

        SFMLMonitorDisplay      &operator=(SFMLMonitorDisplay const &rhs);
        virtual bool            init(uint32_t w, uint32_t h);
        virtual bool            event();
        void                    scroll(float val);
        virtual bool            beforeDisplay();
        virtual bool            afterDisplay();
        virtual sf::Vector2f    baseDisplay(AMonitorModule *amodule, uint32_t nbLines);
        std::string             getLineStr(std::string const &src);
        virtual bool            display(ATitleMonitorModule *module, size_t index, size_t length);
        virtual bool            display(AAttributeListMonitorModule *module, size_t index, size_t length);

        virtual bool        isUnderScreen(size_t sz) const;
        virtual bool        isUpperScreen() const;
    protected:
    private:
        sf::RenderWindow    _window;
        sf::Font            _font;
        float               _lastY;  // last module y position
        float               _scrollY;  // scroll value
        float               _heightContent;  // height of the content
};
