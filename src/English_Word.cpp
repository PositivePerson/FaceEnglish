//
// Created by My on 17.05.2022.
//

#include "../headers/English_Word.h"
#include <iostream>
#include <vector>

using namespace std;

void English_Word::reset() {
    mTriedTimes = 0;
}

std::string English_Word::substr(int aStart, int aEnd) {
    return mValue.substr(aStart, aEnd);
}

void English_Word::erase(int aStart, int aEnd) {
    mValue.erase(aStart, aEnd);
}

size_t English_Word::find(string aPhrase) {
    size_t position = mValue.find(aPhrase);
    return position;
}

void English_Word::addIncorrect() {
//    cout << "mTriedTimes before: " << mTriedTimes <<   endl;
    ++mTriedTimes;
//    cout << "mTriedTimes after: " << mTriedTimes <<   endl;
}

ostream &operator<<(ostream &aOs, English_Word &aD ) {
    string spaces = "";
    for(int i = 0 ; i < 20 - aD.get_length() ; ++i) spaces += ' ';

    string time = "";
    if(aD.mTriedTimes > 1) time = "times";
    else time = "time";

    aOs << aD.mValue << spaces << "\t| mIncorrect " << aD.mTriedTimes << " " << time;
    return aOs;
}

English_Word operator+(English_Word aB, English_Word &aD) {
    aB.set_value(aB.get_value() + ", " + aD.get_value());
    return aB;
}
