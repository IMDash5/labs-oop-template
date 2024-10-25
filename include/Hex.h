#pragma once

#include <string>
#include <initializer_list>
#include <stdexcept>


void validateDigit(unsigned char digit);

class Hex
{
    public:
        Hex();
        Hex(const size_t& length, unsigned char value = 0);
        Hex(const std::initializer_list<unsigned char> &valuesList);
        Hex(const std::string &value);

        Hex(const Hex &other);
        Hex(Hex &&other) noexcept;
        virtual ~Hex() noexcept;

        Hex &operator=(const Hex &other);
        Hex &operator+=(const Hex &other);
        Hex &operator-=(const Hex &other);

        bool operator==(const Hex &other) const;
        bool operator<(const Hex &other) const;
        bool operator>(const Hex &other) const;

        size_t getSize() const;
        unsigned char *getData() const;

    private:
        size_t size_;
        unsigned char *data_;
};

class invalidDigit : public std::invalid_argument {
  public:
   invalidDigit()
       : std::invalid_argument("Invalid digit: It must be between 0 and 15(F)") {}
};

class NegativeSubtraction : public std::invalid_argument {
  public:
   NegativeSubtraction()
       : std::invalid_argument("Negative substraction: Result is negative") {}
};