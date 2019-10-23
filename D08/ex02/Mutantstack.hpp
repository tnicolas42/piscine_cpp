#pragma once

#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class Mutantstack : public std::stack<T, Container> {
    public:
        Mutantstack<T, Container>() : std::stack<T, Container>() {}
        Mutantstack<T, Container>(Mutantstack<T, Container> const &src) : std::stack<T, Container>() {
            *this = src;
        }
        virtual ~Mutantstack<T, Container>() {}

        Mutantstack<T, Container> &operator=(Mutantstack<T, Container> const &rhs) {
            if (this != &rhs) {
                ;
            }
            return this;
        }

        // define oprators typedef
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;

        // define begin & end functions
        typename Container::iterator begin() {
            return std::begin(std::stack<T, Container>::c);
        }
        typename Container::iterator end() {
            return std::end(std::stack<T, Container>::c);
        }
        typename Container::const_iterator begin() const {
            return std::begin(std::stack<T, Container>::c);
        }
        typename Container::const_iterator end() const {
            return std::end(std::stack<T, Container>::c);
        }
    protected:
    private:
};
