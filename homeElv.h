#pragma once
#include <iostream>

using std::string;
using std::cout;
using std::cin;

class HomeElv {
private:
    static const uint32_t numbElv = 1;
    string nameElv[numbElv];

public:
    HomeElv();
    void settlingElv();
    bool findingElv(const string& name) const;
    uint32_t numbSettElv() const;
};

