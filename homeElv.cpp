#include "homeElv.h"

const uint32_t HomeElv::numbElv;

HomeElv::HomeElv() {

   for(uint32_t i = 0; i < numbElv; i++)
       nameElv[i] = "None";
}

void HomeElv::settlingElv() {
    string name;

    for(uint32_t i = 0; i < numbElv; i++){
        cout << "\nEnter the name of the elf: ";
        cin >> name;

        if(name == "None" || name == "none") continue;

        nameElv[i] = name;
    }
}

bool HomeElv::findingElv(const string& name) const{

    if(name == "None" || name == "none") return false;

    for(uint32_t i = 0; i < numbElv; i++)
        if(nameElv[i] == name) return true;

    return false;
}

uint32_t HomeElv::numbSettElv() const{
    uint32_t number = 0;

    for(uint32_t i = 0; i < numbElv; i++)
        if(nameElv[i] != "None" && nameElv[i] != "none") number++;

    return number;
}