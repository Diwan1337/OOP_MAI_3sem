#include "remove_vowels.h"
#include <unordered_set>

std::string remove_vowels(const std::string &input) {
    static const std::unordered_set<char> vowels = {
        'a','e','i','o','u','y','A','E','I','O','U','Y'
    };

    std::string result;
    result.reserve(input.size()); // чтобы не пересоздавать память

    for (char c : input) {
        if (vowels.find(c) == vowels.end()) {
            result.push_back(c);
        }
    }

    return result;
}
