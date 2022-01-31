#include "village.h"

int main(){

    Village elfVillage;
    string elfName, answer;
    uint32_t numb;

    elfVillage.settlingVillage();

    do{
        cout << "\nEnter the name of the elf to search in the village: ";
        cin >> elfName;

        numb = elfVillage.numbElvOnBigBranch(elfName);

        if(numb) cout << "\nThe total number of elves living with " << elfName <<
                      " is " << numb << " !";
        else cout << "\nElf " << elfName << " not found in the village.";

        cout << "\nContinue searching (y/n)?: ";
        cin >> answer;

    }while(answer == "y" || answer != "Y");

    return 0;
}