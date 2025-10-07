#ifndef OCTAL_H
#define OCTAL_H

#include <cstddef>
#include <string>
#include <initializer_list>

class Octal {
private:
    unsigned char* digits;
    size_t size;
    
    void validateDigit(unsigned char digit) const;
    void removeLeadingZeros();

public:
    Octal();
    Octal(const size_t& n, unsigned char t = 0);
    Octal(const std::initializer_list<unsigned char>& t);
    Octal(const std::string& t);
    Octal(const Octal& other);
    Octal(Octal&& other) noexcept;
    virtual ~Octal() noexcept;

    Octal add(const Octal& other) const;
    Octal subtract(const Octal& other) const;
    Octal copy() const;
    
    bool equals(const Octal& other) const;
    bool greater(const Octal& other) const;
    bool less(const Octal& other) const;
    
    std::string toString() const;
    size_t getSize() const;
};

#endif
