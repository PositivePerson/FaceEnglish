//
// Created by My on 13.05.2022.
//

#include "../headers/Chapter.h"
#include "../headers/Polish_Word.h"
#include "../headers/English_Word.h"
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
//    for(English_Word i : eng_words){
//        cout << "i = " << i.get_value() << endl;
//        lines_amount++;
//    }
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
    string temp_pl_imp;
    string temp_eng_imp;

//    ifstream UrLanguage(pl_name + ".txt");
//    ifstream EnglishWords(eng_name + ".txt");

    ifstream UrLanguage(pl_name);
    ifstream EnglishWords(eng_name);

    while(getline(UrLanguage,temp_pl_imp) && getline(EnglishWords,temp_eng_imp)){
        English_Word temp_eng_obj(temp_eng_imp);
        Polish_Word temp_pl_obj(temp_pl_imp, temp_eng_obj);

        pl_word.push_back(temp_pl_obj);
        eng_words.push_back(temp_eng_obj);
//        divide_words(temp_eng);
    }
}

int Chapter::get_lines_amount() {
    return lines_amount;
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
////    for(string i : temp){
////        cout << "temp = " << i << endl;
////    }
//}