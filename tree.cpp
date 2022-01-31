#include "tree.h"

Tree::Tree() {
    uint32_t numbBigBranch, numbMidBranch;
    Branch* branch;

    if(BIG_MAX < BIG_MIN || MID_MAX < MID_MIN){
        cout << "\nError: the maximum possible number of branches cannot be \n"
                "less than the minimum.";
        exit(1);
    }

    srand(time(nullptr));
    numbBigBranch = rand() % (BIG_MAX - BIG_MIN + 1) + BIG_MIN;

    bigBranches = new Branch[numbBigBranch];



    for(uint32_t i = 0; i < numbBigBranch; i++){

        numbMidBranch = rand() % (MID_MAX - MID_MIN + 1) + MID_MIN;

        branch = new Branch[numbMidBranch];

        bigBranches[i].putNextBranch(branch);
        massBranches.push_back(numbMidBranch);
    }
}

Tree::~Tree() {
    uint32_t numbBig = massBranches.size();
    Branch* midBranches;

    for(uint32_t i = 0; i < numbBig; i++){
        midBranches = bigBranches[i].getNextBranch();
        delete midBranches;
    }

    delete bigBranches;
}

void Tree::settlingTree() {

    Branch* midBranch;

    for(uint32_t i = 0; i < massBranches.size(); i++){
        cout << "\nThe " << i + 1 << " big branch: ";
        bigBranches[i].homeBranch().settlingElv();

        midBranch = bigBranches[i].getNextBranch();

        for(uint32_t j = 0; j < massBranches[i]; j++){
            cout << "\nthe " << j + 1 << " middle branch: ";
            midBranch[j].homeBranch().settlingElv();
        }
    }
}

uint32_t Tree::numbElvOnBigBranch(const uint32_t &serialNumb) const{
    uint32_t number = 0;
    uint32_t numMid = massBranches[serialNumb];
    Branch* midBranches = bigBranches[serialNumb].getNextBranch();

    number += bigBranches[serialNumb].homeBranch().numbSettElv();

    for(int j = 0; j < numMid; j++){
        number += midBranches[j].homeBranch().numbSettElv();
    }

    return number;
}

uint32_t Tree::numbSettElv(const string &name) const{
    uint32_t numbElv = 0;
    uint32_t numBig = massBranches.size();
    uint32_t numMid;

    Branch* midBranches;

    for(uint32_t i = 0; i < numBig; i++){

        midBranches = bigBranches[i].getNextBranch();
        numMid = massBranches[i];

        if(bigBranches[i].homeBranch().findingElv(name)){

            numbElv += numbElvOnBigBranch(i);
            continue;
        }

        for(uint32_t j = 0; j < numMid; j++){

            if(midBranches[j].homeBranch().findingElv(name)){

                numbElv += numbElvOnBigBranch(i);
                continue;
            }
        }
    }
    return numbElv;
}
