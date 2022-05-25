//
// Created by My on 13.05.2022.
//

#include "../headers/Word.h"
#include <iostream>
using namespace std;

Word::Word(){
    cout << "\n - First constructor (Word without argument) \n";
}

Word::Word(string a)
{
    cout << "\n\n";

    value = a;
    length = a.length();

    info();
}

void Word::info()
{
    cout << "value = " << value << " \n";
    cout << "length = " << length << " \n";
//    cout << "-------------------------- \n";
}

string Word::get_value() {
    return value;
}
void Word::set_value(string argValue) {
    value = argValue;
}

int Word::get_incorrect_num() {
    return incorrect_ans;
}

int Word::get_hints_num() {
    return hints;
}

void Word::count_incorrect() {
    incorrect_ans++;
}

void Word::count_hints() {
    hints++;
}

int Word::get_length() {
    return length;
}
