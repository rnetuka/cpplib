//
// Created by rnetuka on 05.01.22.
//

#pragma once

#include <regex>
#include "string.h"

namespace lib::regex {

    class SearchResult {
    private:
        vector<string> found;
        vector<int> positions;

    public:
        string group(int i) const;
        int position(int i) const;

        auto begin() const -> decltype(found.begin());
        auto end() const -> decltype(found.end());

        operator bool() const;
        string operator[](int i) const;

        friend SearchResult search(const string& str, const string& pattern);
    };



    SearchResult search(const string& str, const string& pattern);

}