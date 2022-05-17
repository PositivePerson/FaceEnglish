//
// Created by My on 13.05.2022.
//

#include "../headers/Chapter.h"
#include <iostream>
#include <fstream>
//#include <cstddef>
//#include <commctrl.h>

using namespace std;

Chapter::Chapter(string pl_name, string eng_name)
{
    cout << "- First constructor (Chapter) \n";

//    pl_file_name = pl_name;
//    eng_file_name = eng_name;

    fetch_lines(pl_name, eng_name);
    info();
};

void Chapter::info()
{
    cout << "========================= \n";
    for(string i : eng_words){
        cout << "i = " << i << endl;
        lines_amount++;
    }
//    cout << "pl_file_name = " << pl_file_name << " \n";
//    cout << "eng_file_name = " << eng_file_name << " \n";
    cout << "lines_amount = " << lines_amount << " \n";
    cout << "correct = " << correct << " \n";
    cout << "incorrect = " << incorrect << " \n";
    cout << "========================= \n";
}

void Chapter::reset_counters() {
    lines_amount = 0;
    correct = 0;
    incorrect = 0;
}

void Chapter::fetch_lines(string pl_name, string eng_name) {
    string temp_pl;
    string temp_eng;

//    ifstream UrLanguage(pl_name + ".txt");
//    ifstream EnglishWords(eng_name + ".txt");

    ifstream UrLanguage(pl_name);
    ifstream EnglishWords(eng_name);

    while(getline(UrLanguage,temp_pl) && getline(EnglishWords,temp_eng)){
        pl_word.push_back(temp_pl);
        eng_words.push_back(temp_eng);
        divide_words(temp_eng);
    }
}

//void Chapter::divide_words(string line) {
//    vector<string> temp;
//    std::size_t position = 51;
//
//    do{
//        position = line.find("OR");
//        if(position<50){
//            temp.push_back(line.substr(0, position-1));
//            line.erase(0, position+3);
//        }
//        else{
//            temp.push_back(line);
//        }
//    }while(position<50);
//
//    for(string i : temp){
//        cout << "temp = " << i << endl;
//    }
//}