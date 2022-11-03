//
// Created by rnetuka on 05.01.22.
//

#include "regex.h"

namespace lib::regex {

    SearchResult search(const string& str, const string& pattern) {
        SearchResult result;
        std::string s = str;
        std::string p = pattern;
        std::smatch match;
        std::regex_search(s, match, std::regex(p));
        for (int i = 0; i < match.size(); i++) {
            result.found.push_back(match[i].str());
            result.positions.push_back(match.position(i));
        }
        return result;
    }

    string SearchResult::group(int i) const {
        return found[i];
    }

    int SearchResult::position(int i) const {
        return positions[i];
    }

    auto SearchResult::begin() const -> decltype(found.begin()) {
        return found.begin();
    }

    auto SearchResult::end() const -> decltype(found.end()) {
        return found.end();
    }

    SearchResult::operator bool() const {
        return !found.empty();
    }

    string SearchResult::operator[](int i) const {
        return found[i];
    }

}