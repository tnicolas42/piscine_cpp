#include "Convert.hpp"
#include <iostream>
#include <cctype>
#include <limits>
#include <regex>

Convert::Convert() :
_val(""),
_valdError(false) {
    _init();
}

Convert::Convert(std::string val) :
_val(val) {
    _init();
}

void Convert::_init() {
    try {
        _vald = toDouble();
    }
    catch (ConvertError &e) {
        _valdError = true;
    }
}

Convert::Convert(Convert const &src) {
    *this = src;
}

Convert::~Convert() {
}

Convert &Convert::operator=(Convert const &rhs) {
    if (this != &rhs) {
        _val = getVal();
    }
    return *this;
}

char Convert::toChar() const {
    if (!_valdError) {
        if (toInt() >= 32 && toInt() <= 126) {
            return static_cast<char>(toInt());
        }
    }
    throw ConvertDisplayError();
}
int Convert::toInt() const {
    if (!_valdError) {
        if (_vald > static_cast<double>(std::numeric_limits<int>::max())
        || _vald < static_cast<double>(std::numeric_limits<int>::min())
        || _vald != _vald) {  // nan
            throw ConvertImpossibleError();
        }
        return static_cast<int>(_vald);
    }
    throw ConvertImpossibleError();
}
float Convert::toFloat() const {
    if (!_valdError) {
        if (_vald == static_cast<double>(std::numeric_limits<float>::infinity())
        || _vald == static_cast<double>(-std::numeric_limits<float>::infinity())) {
            return static_cast<float>(_vald);
        }
        return static_cast<float>(_vald);
    }
    throw ConvertImpossibleError();
}
double Convert::toDouble() const {
    static std::string notNumbers[] = {
        "nan",
        "inf",
        "-inf",
        "nanf",
        "inff",
        "-inff"
    };
    std::string lowerVal = _val;
    for (uint16_t i=0; i < lowerVal.size(); i++) {
        lowerVal[i] = tolower(lowerVal[i]);
    }
    if (std::regex_match(_val, std::regex("^[-+]?\\d+\\.?\\d*f?$")))
        return std::stod(_val);
    for (uint16_t i=0; i < sizeof(notNumbers) / sizeof(notNumbers[0]); i++) {
        if (lowerVal == notNumbers[i]) {
            return std::stod(_val);
        }
    }
    throw ConvertImpossibleError();
}

std::string const &Convert::getVal() const { return _val; }