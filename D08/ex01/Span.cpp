#include "Span.hpp"
#include <limits>

Span::Span() : _size(0), _nbSettedNb(0), _arr(_size, 0) {}

Span::Span(uint32_t size) : _size(size), _nbSettedNb(0), _arr(_size, 0) {}

Span::Span(Span const &src) {
    *this = src;
}

Span::~Span() {
}

Span &Span::operator=(Span const &rhs) {
    if (this != &rhs) {
        _size = rhs.size();
        _arr.resize(_size);
        for (uint32_t i=0; i < _size; i++)
            _arr[i] = rhs.getArray()[i];
    }
    return *this;
}

void Span::addNumber(int nb) {
    if (_nbSettedNb >= _size)
        throw SpanListFullError();
    _arr[_nbSettedNb] = nb;
    _nbSettedNb++;
}

uint32_t Span::shortestSpan() {
    if (_nbSettedNb <= 1)
        throw SpanNumberSmallError();
    uint32_t minSpan = std::numeric_limits<uint32_t>::max();
    for (std::vector<int>::iterator it = _arr.begin(); it != _arr.begin()+_nbSettedNb; it++) {
        for (std::vector<int>::iterator it2 = it+1; it2 != _arr.begin()+_nbSettedNb; it2++) {
            if (*it == *it2) {
                return 0;
            }
            else if (*it > *it2) {
                minSpan = (static_cast<uint32_t>(*it - *it2) < minSpan) ? static_cast<uint32_t>(*it - *it2) : minSpan;
            }
            else {
                minSpan = (static_cast<uint32_t>(*it2 - *it) < minSpan) ? static_cast<uint32_t>(*it2 - *it) : minSpan;
            }
        }
    }
    return minSpan;
}

uint32_t Span::longestSpan() {
    if (_nbSettedNb <= 1)
        throw SpanNumberSmallError();
    int max_ = *std::max_element(_arr.begin(), _arr.begin()+_nbSettedNb);
    int min_ = *std::min_element(_arr.begin(), _arr.begin()+_nbSettedNb);
    return static_cast<uint32_t>(max_ - min_);
}

uint32_t Span::size() const { return _size; }
std::vector<int> const &Span::getArray() const { return _arr; }
std::vector<int> &Span::getArray() { return _arr; }

const char *Span::SpanError::what() const throw() {
    return "error in span";
}
const char *Span::SpanListFullError::what() const throw() {
    return "the list is already full";
}
const char *Span::SpanNumberSmallError::what() const throw() {
    return "the span contain less than 2 numbers";
}
