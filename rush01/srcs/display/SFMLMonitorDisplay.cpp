#include "SFMLMonitorDisplay.hpp"
#include <iostream>

SFMLMonitorDisplay::SFMLMonitorDisplay() :
AMonitorDisplay(),
_window(),
_font(),
_lastY(0),
_scrollY(0),
_heightContent(0) {
}

SFMLMonitorDisplay::SFMLMonitorDisplay(SFMLMonitorDisplay const &src) :
AMonitorDisplay(src) {
    *this = src;
}

SFMLMonitorDisplay::~SFMLMonitorDisplay() {
    _window.close();
}

SFMLMonitorDisplay &SFMLMonitorDisplay::operator=(SFMLMonitorDisplay const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}


bool        SFMLMonitorDisplay::init(uint32_t w, uint32_t h) {
    if (AMonitorDisplay::init(w, h) == false)
        return false;
    if (_width < DISPLAY_SFML_MIN_WIDTH || _width > DISPLAY_SFML_MAX_WIDTH) {
        std::cerr << "invalid width (btw " << DISPLAY_SFML_MIN_WIDTH << " and " << DISPLAY_SFML_MAX_WIDTH << ")" << std::endl;
        return false;
    }
    if (_height < DISPLAY_SFML_MIN_HEIGHT || _height > DISPLAY_SFML_MAX_HEIGHT) {
        std::cerr << "invalid height (btw " << DISPLAY_SFML_MIN_HEIGHT << " and " << DISPLAY_SFML_MAX_HEIGHT << ")" << std::endl;
        return false;
    }

    _window.create(sf::VideoMode(_width, _height), "ft_gkrellm", sf::Style::Close);

    if (!_font.loadFromFile(DISPLAY_SFML_FONT)) {
        return false;
    }

    return true;
}

void        SFMLMonitorDisplay::scroll(float val) {
    if (_scrollY + val >= 0) {
        _scrollY = 0;
    }
    else {
        _scrollY += val;
    }
}

bool        SFMLMonitorDisplay::event() {
    sf::Event event;
    while (_window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                _isQuit = true;
                break;

            case sf::Event::Resized:
                _width = event.size.width;
                _height = event.size.height;
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Q) {
                    _isQuit = true;
                }
                else if (event.key.code == sf::Keyboard::Up) {
                    scroll(_width * DISPLAY_SFML_SCROLL_UP_KEY_PERCENT);
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    scroll(-(_width * DISPLAY_SFML_SCROLL_UP_KEY_PERCENT));
                }
                break;

            default:
                break;
        }
    }
    return true;
}

bool        SFMLMonitorDisplay::beforeDisplay() {
    _lastY = 0;
    event();
    _window.clear(DISPLAY_SFML_COLOR_BG);
    return true;
}

bool        SFMLMonitorDisplay::afterDisplay() {
    _heightContent = _lastY;
    _window.display();
    return true;
}

sf::Vector2f SFMLMonitorDisplay::baseDisplay(AMonitorModule *amodule, uint32_t nbLines) {
    nbLines += 1;  // for the name
    // draw rectangle
    float x = _width * DISPLAY_SFML_BORDER_PAD_PERCENT;
    float y = _width * DISPLAY_SFML_BORDER_PAD_PERCENT + _lastY + _scrollY;
    float w = _width * (1 - (2 * DISPLAY_SFML_BORDER_PAD_PERCENT));
    float h = _width * DISPLAY_SFML_LINE_HEIGHT_PERCENT * nbLines;
    _lastY += h + _width * DISPLAY_SFML_BORDER_PAD_PERCENT;

    sf::RectangleShape rectangle(sf::Vector2f(w, h));
    rectangle.setPosition(sf::Vector2f(x, y));
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(_width * DISPLAY_SFML_BORDER_SZ_PERCENT);
    rectangle.setOutlineColor(DISPLAY_SFML_COLOR_RECT);
    _window.draw(rectangle);

    // draw name
    sf::Text name;
    float xTxt = x + _width * DISPLAY_SFML_TEXT_PAD_PERCENT;
    float yTxt = y;

    name.setFont(_font);
    name.setString(amodule->getName());
    name.setCharacterSize(_width * DISPLAY_SFML_TITLE_SIZE_PERCENT);
    name.setStyle(sf::Text::Bold);
    name.setPosition(sf::Vector2f(xTxt, yTxt));
    _window.draw(name);

    return sf::Vector2f(xTxt + _width * DISPLAY_SFML_TEXT_PAD_PERCENT,
        yTxt + _width * DISPLAY_SFML_LINE_HEIGHT_PERCENT);  // return pos for next line
}

std::string SFMLMonitorDisplay::getLineStr(std::string const &src) {
    if (src.size() <= DISPLAY_SFML_MAX_CHAR_LINE)
        return std::string(src);
    return std::string(src.substr(0, DISPLAY_SFML_MAX_CHAR_LINE - 4) + " ...");
}

bool        SFMLMonitorDisplay::display(ATitleMonitorModule *module, size_t index, size_t length) {
    (void)index;
    (void)length;
    // draw rectangle and name
    sf::Vector2f pos = baseDisplay(module, 1);  // display for 1 lines

    // draw content
    sf::Text value;

    value.setFont(_font);
    value.setString(getLineStr(module->getValue()));
    value.setCharacterSize(_width * DISPLAY_SFML_TEXT_SIZE_PERCENT);
    value.setPosition(sf::Vector2f(pos.x, pos.y));

    _window.draw(value);
    return true;
}

bool        SFMLMonitorDisplay::display(AAttributeListMonitorModule *module, size_t index, size_t length) {
    (void)index;
    (void)length;
    std::vector<Attribute> const attr = module->getAttributes();

    // draw rectangle and name
    sf::Vector2f pos = baseDisplay(module, attr.size());

    // draw content
    sf::Text value;

    value.setFont(_font);
    value.setCharacterSize(_width * DISPLAY_SFML_TEXT_SIZE_PERCENT);
    for (uint32_t i=0; i < attr.size(); i++) {
        std::string str = attr[i].getName() + ": " + attr[i].getValue();
        value.setString(getLineStr(str));
        value.setPosition(sf::Vector2f(pos.x, pos.y + i * _width * DISPLAY_SFML_LINE_HEIGHT_PERCENT));
        _window.draw(value);
    }

    return true;
}

bool        SFMLMonitorDisplay::isUnderScreen(size_t sz) const {
    // if (_lastY + _scrollY + _width * DISPLAY_SFML_LINE_HEIGHT_PERCENT * sz < 0)
    //     return true;
    (void)sz;
    return false;
}
bool        SFMLMonitorDisplay::isUpperScreen() const {
    if (_lastY + _scrollY > _height)
        return true;
    return false;
}
