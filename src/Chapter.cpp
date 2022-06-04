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

//    counter = new Counter();

    fetch_lines(pl_name, eng_name);
    info();
};

void Chapter::info()
{
    cout << "========================= \n";
    cout << "lines_amount = " << lines_amount << " \n";
    cout << "correct = " << counter.get_correct_num() << " \n";
    cout << "incorrect = " << counter.get_incorrect_num() << " \n";
    cout << "========================= \n";
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

        lines_amount++;
//        divide_words(temp_eng);
    }
}

void Chapter::set_word_to_study(Polish_Word *word) {
    cout << "Copied obj destination: " << &((*word).get_translations()[0]) << endl;
    to_study.push_back(*word);
}

void Chapter::reset_to_study() {
    to_study.clear();
}

void Chapter::filter_to_incorrect() {
    pl_word.clear();
    for(auto word : to_study) {
        word.reset_translations_counters();

        const Polish_Word temp = word;
        pl_word.push_back(temp);
    }

// It works, but lets use OPERATOR= overload
//    pl_word = to_study;

    reset_to_study();
}

int Chapter::get_lines_amount() {
    return lines_amount;
}

vector<Polish_Word> Chapter::get_pl_words() {
    return pl_word;
};

vector<Polish_Word> Chapter::get_words_to_study() {
    return to_study;
};

//Polish_Word operator+(Polish_Word const &a, Polish_Word const &b) {
//    return Polish_Word(a);
//};

Chapter::~Chapter() {
//    delete counter;
}