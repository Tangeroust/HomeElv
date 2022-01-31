#include "branch.h"

Branch::Branch() : home(HomeElv()), next(nullptr)
{   }

Branch::~Branch(){
    delete next;
}

void Branch::putNextBranch(Branch *nt) {

    if(!nt){
        cout << "\nError: address must not be null.";
        exit(2);
    }

    next = nt;
}

Branch* Branch::getNextBranch() const{
    return next;
}

HomeElv& Branch::homeBranch() {
    return home;
}


