#include "PhoneContact.hpp"
#include <iostream>

PhoneContact::PhoneContact() :
  _isInit(false),
  _id(_nbInstance),
  _firstName(""),
  _lastName(""),
  _nickname(""),
  _login(""),
  _postalAddress(""),
  _mail(""),
  _phone(""),
  _birthDayDate(""),
  _favMeal(""),
  _undewearColor(""),
  _secret("")
{
    PhoneContact::_nbInstance++;
}

void PhoneContact::init() {
    _set("First name", _firstName);
    _set("Last name", _lastName);
    _set("Nickname", _nickname);
    _set("Login", _login);
    _set("Postal address", _postalAddress);
    _set("Mail", _mail);
    _set("Phone", _phone);
    _set("Birthday", _birthDayDate);
    _set("Favorite meal", _favMeal);
    _set("Underwear color", _undewearColor);
    _set("darkest secret", _secret);
    _isInit = true;
}

void PhoneContact::_set(const std::string txt, std::string &var) {
    std::cout << txt << ": ";
    std::cin >> var;
}

void getChars(char dest[SZ_COL+1], const std::string &src) {
    dest[SZ_COL] = '\0';
    if (src.size() <= SZ_COL) {
        for (uint32_t i=0; i < SZ_COL - src.size(); i++) {
            dest[i] = ' ';
        }
        for (uint32_t i=SZ_COL - src.size(); i < SZ_COL; i++) {
            dest[i] = src[i-(SZ_COL - src.size())];
        }
    }
    else {
        for (uint32_t i=0; i < SZ_COL - 1; i++) {
            dest[i] = src[i];
        }
        dest[SZ_COL-1] = '.';
    }
}

void PhoneContact::displayCompact() const {
    char index[SZ_COL+1];
    char fname[SZ_COL+1];
    char lname[SZ_COL+1];
    char nname[SZ_COL+1];

    getChars(index, std::to_string(_id));
    getChars(fname, _firstName);
    getChars(lname, _lastName);
    getChars(nname, _nickname);

    std::cout << "|" << index << "|" << fname << "|" << lname << "|" << nname << "|" << std::endl;
}

void PhoneContact::display() const {
    _show("First name", _firstName);
    _show("Last name", _lastName);
    _show("Nickname", _nickname);
    _show("Login", _login);
    _show("Postal address", _postalAddress);
    _show("Mail", _mail);
    _show("Phone", _phone);
    _show("Birthday", _birthDayDate);
    _show("Favorite meal", _favMeal);
    _show("Underwear color", _undewearColor);
    _show("darkest secret", _secret);
}

void PhoneContact::_show(const std::string txt, const std::string var) const {
    std::cout << txt << ": " << var << std::endl;
}

bool PhoneContact::isInit() const { return _isInit; }

PhoneContact::~PhoneContact() {}

uint32_t PhoneContact::_nbInstance = 0;