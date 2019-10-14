#pragma once

#include <string>

#define SZ_COL 10

class PhoneContact {
    public:
        PhoneContact();
        ~PhoneContact();

        void init();
        bool isInit() const;
        void displayCompact() const;
        void display() const;
    protected:
    private:
        static uint32_t _nbInstance;
        bool _isInit;
        uint32_t _id;
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _login;
        std::string _postalAddress;
        std::string _mail;
        std::string _phone;
        std::string _birthDayDate;
        std::string _favMeal;
        std::string _undewearColor;
        std::string _secret;

        void _set(const std::string txt, std::string &var);
        void _show(const std::string txt, const std::string var) const;
};