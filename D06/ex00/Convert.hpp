#pragma once

#include <string>
#include <stdexcept>

class Convert {
    public:
        Convert();
        Convert(std::string val);
        Convert(Convert const &src);
        virtual ~Convert();

        Convert &operator=(Convert const &rhs);

        /* convert */
        char toChar() const;
        int toInt() const;
        float toFloat() const;
        double toDouble() const;

        // getter
        std::string const &getVal() const;

        class ConvertError : public std::exception {};
        class ConvertImpossibleError : public ConvertError {
            public:
                virtual const char *what() const throw() {
                    return "impossible";
                }
        };
        class ConvertDisplayError : public ConvertError {
            public:
                virtual const char *what() const throw() {
                    return "Non displayable";
                }
        };
    protected:
    private:
        void _init();

        std::string _val;
        double _vald;
        bool _valdError;
};