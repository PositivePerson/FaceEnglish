//
// Created by My on 13.05.2022.
//

#include "../headers/Word.h"
#include <iostream>
using namespace std;

Word::Word(){
//    cout << "\n - First constructor (Word without argument) \n";
}

Word::Word(string a)
{
    value = a;
    length = a.length();

//    info();
}

void Word::info()
{
    cout << endl;
    cout << "============ DEBUG (dev mode)  ============" << endl;
    cout << "value = " << value << " \n";
//    cout << "===============================" << endl;
}

string Word::get_value() {
    return value;
}
void Word::set_value(string argValue) {
    value = argValue;
}

int Word::get_hints_num() {
    return hints;
}

void Word::count_hints() {
    hints++;
}

int Word::get_length() {
    return length;
}
