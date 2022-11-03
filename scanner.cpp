//
// Created by rnetuka on 07.01.22.
//

#include <regex>
#include "scanner.h"

namespace lib {

    vector<ScanResult> scan(const string& str, const string& pattern) {
        vector<ScanResult> results;
        std::string s = str;
        std::string::const_iterator it { s.cbegin() };
        std::string p = pattern;
        std::smatch match;
        int offset = 0;
        while (std::regex_search(it, s.cend(), match, std::regex(p))) {
            results.push_back({ match[0].str(), (int) match.position(0) + offset });
            it = match.suffix().first;
            offset = it - s.cbegin();
        }
        return results;
    }

    ScanResult::ScanResult(const string& string, int position) : str { string }, position { position }, length { str.length } {

    }

    ScanResult::operator string() const {
        return str;
    }

}