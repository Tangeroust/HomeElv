#include "village.h"

const uint32_t Village::NUMB_TREE;

uint32_t Village::numbElvOnBigBranch(const string &name) const {
    uint32_t numb = 0;

    for(uint32_t i = 0; i < NUMB_TREE; i++)
        numb += trees[i].numbSettElv(name);

    return numb;
}

void Village::settlingVillage() {
    for(uint32_t i = 0; i < NUMB_TREE; i++){
        cout << "\nThe " << i + 1 << " tree:";
        trees[i].settlingTree();
    }
}