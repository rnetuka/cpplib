//
// Created by rnetuka on 04.01.22.
//

#pragma once

#include "iostream.h"
#include "string.h"
#include "containers/vector.h"

namespace lib {

    class Integer {
    private:
        long value;

    public:
        Integer();
        Integer(int value);
        Integer(long value);
        Integer(const string& string);
        static Integer from_hex(char hex);
        static Integer from_hex(const string& string);
        static Integer from_bin(const string& string);
        static Integer from_digits(const vector<int>& digits);

        string hex() const;
        string bin() const;

        vector<int> digits() const;

        operator int() const;

        Integer& operator++();
        Integer& operator++(int);
        Integer& operator--();
        Integer& operator--(int);
        bool operator==(const Integer& other) const;
        bool operator<=(const Integer& other) const;
        bool operator>=(const Integer& other) const;
        bool operator<(const Integer& other) const;
        bool operator>(const Integer& other) const;

        friend ostream& operator<<(ostream& stream, const Integer& number);
    };

    using integer = Integer;

    int min(int a, int b);
    int max(int a, int b);

}