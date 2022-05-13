//
// Created by My on 13.05.2022.
//

#include "../headers/Chapter.h"
#include <iostream>
#include <fstream>

using namespace std;

Chapter::Chapter(string pl_name, string eng_name)
{
    cout << "- First constructor (Chapter) \n";

//    pl_file_name = pl_name;
//    eng_file_name = eng_name;

    fetch_lines(pl_name, eng_name);
    lines_amount = pl_name.size();

    info();
};

void Chapter::info()
{
    cout << "========================= \n";
//    cout << "pl_file_name = " << pl_file_name << " \n";
//    cout << "eng_file_name = " << eng_file_name << " \n";
    cout << "lines_amount = " << lines_amount << " \n";
    cout << "correct = " << correct << " \n";
    cout << "incorrect = " << incorrect << " \n";

    for(string i : pl_words)
        cout << "i = " << i << endl;
    cout << "========================= \n";
}

void Chapter::fetch_lines(string pl_name, string eng_name) {
    string pl_temp;
    string eng_temp;

//    ifstream UrLanguage(pl_name + ".txt");
//    ifstream EnglishWords(eng_name + ".txt");

    ifstream UrLanguage(pl_name);
    ifstream EnglishWords(eng_name);

    while(getline(EnglishWords,pl_temp) && getline(UrLanguage,eng_temp)){
        pl_words.push_back(pl_temp);
        eng_words.push_back(eng_temp);
//        cout<<"pl_temp: "<< pl_temp <<"\n";
    }
}