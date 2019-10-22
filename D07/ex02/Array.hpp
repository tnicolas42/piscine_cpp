#pragma once

#include <ctype.h>
#include <stdexcept>

template<typename T>
class Array {
    public:
        Array<T>() : _size(0), _content(nullptr) {}
        Array<T>(size_t size) : _size(size), _content(new T[size]) {}
        Array<T>(Array<T> const &src) : _size(0), _content(nullptr) {
            *this = src;
        }
        virtual ~Array<T>() {
            delete [] _content;
        }

        Array<T> &operator=(Array<T> const &rhs) {
            if (this != &rhs) {
                _size = rhs.size();
                delete [] _content;  // delete if there is a content
                _content = new T[_size];
                for (uint32_t i=0; i < _size; i++) {
                    _content[i] = rhs[i];
                }
            }
            return *this;
        }

        size_t  size() const { return _size; }

        T &operator[](uint32_t idx) {
            if (idx < _size) {
                return _content[idx];
            }
            throw std::out_of_range("index out of range");
        }
        T const &operator[](uint32_t idx) const {
            if (idx < _size) {
                return _content[idx];
            }
            throw std::out_of_range("index out of range");
        }
    protected:
    private:
        size_t  _size;
        T       *_content;
};
