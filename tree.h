#pragma once
#include <ctime>
#include <vector>
#include "branch.h"

using std::vector;

class Tree {
private:
   enum numbBranch {BIG_MIN = 3, BIG_MAX = 5,
                    MID_MIN = 2, MID_MAX = 3};

   Branch* bigBranches;
   vector <uint32_t> massBranches;

   uint32_t numbElvOnBigBranch(const uint32_t& serialNumb) const;

public:
    Tree();
    ~Tree();

    uint32_t numbSettElv(const string& name) const;
    void settlingTree();
};

