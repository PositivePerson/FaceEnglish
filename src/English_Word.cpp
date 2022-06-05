//
// Created by My on 17.05.2022.
//

#include "../headers/English_Word.h"
#include <iostream>
#include <vector>

using namespace std;

void English_Word::reset() {
    tried_times = 0;
}

std::string English_Word::substr(int start, int end) {
//    value.substr(start, end);
    return value.substr(start, end);
}

void English_Word::erase(int start, int end) {
    value.erase(start, end);
}

size_t English_Word::find(string phrase) {
    size_t position = value.find(phrase);
    return position;
}

void English_Word::add_incorrect() {
//    cout << "tried_times before: " << tried_times <<   endl;
    ++tried_times;
//    cout << "tried_times after: " << tried_times <<   endl;
}

ostream &operator<<(ostream &output, English_Word &D ) {
    string spaces = "";
    for(int i = 0 ; i < 20-D.get_length() ; ++i) spaces += ' ';

    string time = "";
    if(D.tried_times > 1) time = "times";
    else time = "time";

    output << D.value << spaces << "\t| incorrect " << D.tried_times << " " << time;
    return output;
}

English_Word operator+(English_Word B, English_Word &D) {
    B.set_value(B.get_value() + ", " + D.get_value());
    return B;
}
