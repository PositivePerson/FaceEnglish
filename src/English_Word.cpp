//
// Created by My on 17.05.2022.
//

#include "../headers/English_Word.h"
#include <iostream>

using namespace std;

English_Word::English_Word() {
    cout << "- First constructor (English_Word) \n";
}

int English_Word::get_tried_times() {
    return tried_times;
}

void English_Word::substr(int start, int end) {
    value.substr(start, end)
}

void English_Word::erase(int start, int end) {
    mValue.erase(start, end)
}

size_t find(string phrase) {
    size_t position value.find(phrase);
    return position;
}