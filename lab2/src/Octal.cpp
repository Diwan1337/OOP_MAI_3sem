#include "Octal.h"
#include <stdexcept>
#include <algorithm>

void Octal::validateDigit(unsigned char digit) const {
    if (digit > 7) {
        throw std::invalid_argument("Invalid octal digit");
    }
}

void Octal::removeLeadingZeros() {
    while (size > 1 && digits[size - 1] == 0) {
        size--;
    }
}

Octal::Octal() : digits(new unsigned char[1]{0}), size(1) {}

Octal::Octal(const size_t& n, unsigned char t) : size(n) {
    if (n == 0) {
        throw std::invalid_argument("Size must be greater than 0");
    }
    validateDigit(t);
    digits = new unsigned char[size];
    std::fill(digits, digits + size, t);
    removeLeadingZeros();
}

Octal::Octal(const std::initializer_list<unsigned char>& t) : size(t.size()) {
    if (size == 0) {
        throw std::invalid_argument("Initializer list cannot be empty");
    }
    digits = new unsigned char[size];
    size_t i = 0;
    for (auto digit : t) {
        validateDigit(digit);
        digits[i++] = digit;
    }
    removeLeadingZeros();
}

Octal::Octal(const std::string& t) {
    if (t.empty()) {
        throw std::invalid_argument("String cannot be empty");
    }
    
    size = t.length();
    digits = new unsigned char[size];
    
    for (size_t i = 0; i < size; ++i) {
        if (t[i] < '0' || t[i] > '7') {
            delete[] digits;
            throw std::invalid_argument("Invalid octal string");
        }
        digits[size - 1 - i] = t[i] - '0';
    }
    removeLeadingZeros();
}

Octal::Octal(const Octal& other) : size(other.size) {
    digits = new unsigned char[size];
    std::copy(other.digits, other.digits + size, digits);
}

Octal::Octal(Octal&& other) noexcept : digits(other.digits), size(other.size) {
    other.digits = nullptr;
    other.size = 0;
}

Octal::~Octal() noexcept {
    delete[] digits;
}

Octal Octal::add(const Octal& other) const {
    size_t maxSize = std::max(size, other.size);
    size_t resultSize = maxSize + 1;
    unsigned char* result = new unsigned char[resultSize]{0};
    unsigned char carry = 0;
    
    for (size_t i = 0; i < maxSize || carry; ++i) {
        unsigned char sum = carry;
        if (i < size) sum += digits[i];
        if (i < other.size) sum += other.digits[i];
        
        result[i] = sum % 8;
        carry = sum / 8;
    }
    
    Octal res;
    delete[] res.digits;
    res.digits = result;
    res.size = resultSize;
    res.removeLeadingZeros();
    
    return res;
}

Octal Octal::subtract(const Octal& other) const {
    if (less(other)) {
        throw std::invalid_argument("Result would be negative");
    }
    
    unsigned char* result = new unsigned char[size]{0};
    int borrow = 0;
    
    for (size_t i = 0; i < size; ++i) {
        int diff = digits[i] - borrow;
        if (i < other.size) diff -= other.digits[i];
        
        if (diff < 0) {
            diff += 8;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff;
    }
    
    Octal res;
    delete[] res.digits;
    res.digits = result;
    res.size = size;
    res.removeLeadingZeros();
    
    return res;
}

Octal Octal::copy() const {
    return Octal(*this);
}

bool Octal::equals(const Octal& other) const {
    if (size != other.size) return false;
    return std::equal(digits, digits + size, other.digits);
}

bool Octal::greater(const Octal& other) const {
    if (size != other.size) return size > other.size;
    
    for (size_t i = size; i > 0; --i) {
        size_t index = i - 1;
        if (digits[index] != other.digits[index]) {
            return digits[index] > other.digits[index];
        }
    }

    return false;
}

bool Octal::less(const Octal& other) const {
    return !greater(other) && !equals(other);
}

std::string Octal::toString() const {
    std::string result;
    for (size_t i = size; i > 0; --i) {
        result += ('0' + digits[i - 1]);
    }
    return result;
}

size_t Octal::getSize() const {
    return size;
}
