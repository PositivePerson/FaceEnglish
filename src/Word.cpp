//
// Created by My on 13.05.2022.
//

#include "../headers/Word.h"
#include <iostream>
using namespace std;

Word::Word(string a)
{
    value = a;
    length = a.length();

    info();
}

void Word::info()
{
    cout << "- First constructor (Word) \n";
    cout << "value = " << value << " \n";
    cout << "length = " << length << " \n";
    cout << "-------------------------- \n";
}