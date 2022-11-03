//
// Created by rnetuka on 04.01.22.
//

#include <bitset>
#include <sstream>
#include "exception.h"
#include "number.h"

namespace lib {

    Integer::Integer() {
        value = 0;
    }

    Integer::Integer(int value) {
        this->value = value;
    }

    Integer::Integer(long value) {
        this->value = value;
    }

    Integer::Integer(const string& string) {
        if (string.starts_with("0x")) {
            std::stringstream stream;
            stream << std::hex << string;
            stream >> value;
        } else if (string.starts_with("0b")) {
            value = stoi(string, 2);
        } else {
            value = stoi(string);
        }
    }

    Integer Integer::from_hex(char character) {
        string allowed = "0123456789abcdefABCDEF";
        if (! allowed.contains(character))
            throw invalid_argument("");

        string hex { character };
        return Integer::from_hex(hex);
    }

    Integer Integer::from_hex(const string& hex) {
        return hex.starts_with("0x") ? Integer(hex) : Integer(hex.prepend("0x"));
    }

    Integer Integer::from_bin(const string& bin) {
        return { stoi(bin, 2) };
    }

    Integer Integer::from_digits(const vector<int>& digits) {
        Integer result;
        for (int i = 0; i < digits.size(); i++) {
            int digit = digits[i];
            if (digit < 0 || digit > 9)
                throw invalid_argument("Invalid digit");
            result.value += digit;
            if (i < digits.size() - 1)
                result.value *= 10;
        }
        return result;
    }

    string Integer::hex() const {
        std::stringstream stream;
        stream << std::hex << value;
        return stream.str();
    }

    string Integer::bin() const {
        if (value == 0)
            return "0";

        string s = std::bitset<64>(value).to_string();
        int i = s.index_of("1");
        return s.substring(i);
    }

    vector<int> Integer::digits() const {
        vector<int> digits;
        long n = value;
        while (n > 0) {
            digits.push_front(n % 10);
            n /= 10;
        }
        return digits;
    }

    Integer::operator int() const {
        return value;
    }

    Integer& Integer::operator++() {
        value++;
        return *this;
    }

    Integer& Integer::operator++(int) {
        value++;
        return *this;
    }

    Integer& Integer::operator--() {
        value--;
        return *this;
    }

    Integer& Integer::operator--(int) {
        value--;
        return *this;
    }

    bool Integer::operator==(const Integer& other) const {
        return value == other.value;
    }

    bool Integer::operator<=(const Integer& other) const {
        return value <= other.value;
    }

    bool Integer::operator>=(const Integer& other) const {
        return value >= other.value;
    }

    bool Integer::operator<(const Integer& other) const {
        return value < other.value;
    }

    bool Integer::operator>(const Integer& other) const {
        return value > other.value;
    }

    int min(int a, int b) {
        return a <= b ? a : b;
    }

    int max(int a, int b) {
        return a >= b ? a : b;
    }

    ostream& operator<<(ostream& stream, const Integer& number) {
        stream << number.value;
        return stream;
    }

}