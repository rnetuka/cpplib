//
// Created by rnetuka on 07.01.22.
//

#pragma once

#include "string.h"
#include "containers/vector.h"

namespace lib {

    class ScanResult {
    private:
        const string str;

        ScanResult(const string& string, int position);

    public:
        const int position;
        const int length;

        operator string() const;

        friend vector<ScanResult> scan(const string& str, const string& pattern);
    };

    vector<ScanResult> scan(const string& str, const string& pattern);

}