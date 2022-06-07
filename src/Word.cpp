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
    mValue = a;
    mLength = a.length();

//    info();
}

void Word::info()
{
    cout << endl;
    cout << "============ DEBUG (dev mode)  ============" << endl;
    cout << "mValue = " << mValue << " \n";
//    cout << "===============================" << endl;
}

string Word::get_value() {
    return mValue;
}
void Word::set_value(string aArgValue) {
    mValue = aArgValue;
}

int Word::get_hints_num() {
    return mHints;
}

void Word::count_hints() {
    mHints++;
}

int Word::get_length() {
    return mLength;
}
