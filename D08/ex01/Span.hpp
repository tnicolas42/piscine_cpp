#pragma once

#include <vector>
#include <stdexcept>

class Span {
    public:
        Span();
        Span(uint32_t size);
        Span(Span const &src);
        virtual ~Span();

        Span &operator=(Span const &rhs);
        void addNumber(int nb);
        uint32_t shortestSpan();
        uint32_t longestSpan();

        /* getter */
        uint32_t size() const;
        std::vector<int> const &getArray() const;
        std::vector<int> &getArray();

        class SpanError : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class SpanListFullError : public SpanError {
            public:
                virtual const char *what() const throw();
        };
        class SpanNumberSmallError : public SpanError {
            public:
                virtual const char *what() const throw();
        };
    protected:
    private:
        uint32_t        _size;
        uint32_t        _nbSettedNb;
        std::vector<int> _arr;
};
