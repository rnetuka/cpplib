//
// Created by rnetuka on 10.12.21.
//

#pragma once

#include <optional>
#include <string>
#include "containers/vector.h"

namespace lib {

    class String {
    private:
        std::string data;

    public:
        const int length;

        String();
        String(const std::string& data);
        String(const char* data);
        String(int number);
        String(char character);

        [[nodiscard]] String left_trim() const;
        [[nodiscard]] String right_trim() const;
        [[nodiscard]] String trim() const;
        [[nodiscard]] String insert(int i, const String& substring) const;
        [[nodiscard]] String lower_case() const;
        [[nodiscard]] String upper_case() const;
        [[nodiscard]] String substring(int start, int end = -1) const;
        [[nodiscard]] String replace(int i, int length, const String& replacement) const;
        [[nodiscard]] String replace_all(const String& substring, const String& replacement) const;
        [[nodiscard]] String prepend(char c, int times) const;
        [[nodiscard]] String prepend(const String& str) const;

        vector<String> split(char delimiter = ' ') const;
        vector<String> split(const std::string& delimiter) const;
        vector<char> chars() const;

        char char_at(int i) const;
        bool empty() const;
        bool contains(char character) const;
        bool contains(const String& substring) const;
        bool contains_all(const String&  characters) const;
        bool starts_with(const std::string& prefix) const;
        int index_of(const String& substring) const;
        int count(char character) const;

        auto begin() const -> decltype(data.cbegin());
        auto end() const -> decltype(data.cend());

        char operator[](int i) const;
        bool operator==(const String& other) const;
        bool operator<(const String& other) const;
        bool operator>(const String& other) const;
        String& operator=(const String& other);
        String operator+(const char* other) const;
        String operator+(int number) const;
        String operator+(double number) const;
        String& operator+=(char character);
        String& operator+=(int number);
        String& operator+=(const char* str);
        String& operator+=(const String& other);
        operator int() const;
        operator std::string() const;

        friend std::ostream& operator<<(std::ostream& stream, const String& string);
        friend String sorted(const String& string);
    };

    String join(const vector<char>& chars, const String& separator = "");

    using string = String;

    int length(const std::string& string);
    int atoi(char character);
    char itoa(int number);
    int stoi(const String& string, int base = 10);
    long stol(const String& string, int base = 10);

}

template <>
struct std::hash<lib::String> {

    std::size_t operator()(const lib::String& string) const {
        std::hash<std::string> h;
        return h(string);
    }

};