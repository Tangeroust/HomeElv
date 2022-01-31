#pragma once
#include "tree.h"

class Village {
private:
    static const uint32_t NUMB_TREE = 5;
    Tree trees[NUMB_TREE];

public:
    void settlingVillage();
    uint32_t numbElvOnBigBranch(const string& name) const;
};