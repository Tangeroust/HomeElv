#pragma once
#include "homeElv.h"

class Branch{
private:
    HomeElv home;
    Branch* next;

public:
    Branch();
    ~Branch();

    void putNextBranch(Branch* nt);

    Branch* getNextBranch() const;

    HomeElv& homeBranch();
};


