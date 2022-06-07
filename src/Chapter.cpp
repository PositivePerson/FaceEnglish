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

Chapter::Chapter(string aPlName, string aEngName)
{
    cout << "- First constructor (Chapter) \n";

//    pl_file_name = aPlName;
//    eng_file_name = aEngName;

//    counter = new Counter();

    fetchLines(aPlName, aEngName);
    info();
};

void Chapter::info()
{
    cout << "========================= \n";
    cout << "linesAmount = " << linesAmount << " \n";
    cout << "mCorrect = " << counter.getCorrectNum() << " \n";
    cout << "mIncorrect = " << counter.getIncorrectNum() << " \n";
    cout << "========================= \n";
}

void Chapter::fetchLines(string aPlName, string aEngName) {
    string temp_pl_imp;
    string temp_eng_imp;

//    ifstream UrLanguage(aPlName + ".txt");
//    ifstream EnglishWords(aEngName + ".txt");

    ifstream UrLanguage(aPlName);
    ifstream EnglishWords(aEngName);

    while(getline(UrLanguage,temp_pl_imp) && getline(EnglishWords,temp_eng_imp)){
        English_Word temp_eng_obj(temp_eng_imp);
        Polish_Word temp_pl_obj(temp_pl_imp, temp_eng_obj);

        plWord.push_back(temp_pl_obj);
        engWords.push_back(temp_eng_obj);

        linesAmount++;
//        divide_words(temp_eng);
    }
}

void Chapter::setWordToStudy(Polish_Word *aWord) {
//    cout << "Copied obj destination: " << &((*aWord).get_translations()[0]) << endl;
    toStudy.push_back(*aWord);
}

void Chapter::resetToStudy() {
    toStudy.clear();
}

void Chapter::filterToIncorrect() {
    plWord.clear();
    for(auto word : toStudy) {
//        word.reset_translations_counters();
        word.reset_counters();

        const Polish_Word temp = word;
        plWord.push_back(temp);
    }

// It works, but lets use OPERATOR= overload
//    plWord = toStudy;

    resetToStudy();
}

int Chapter::getLinesAmount() {
    return linesAmount;
}

vector<Polish_Word> Chapter::getPlWords() {
    return plWord;
};

vector<Polish_Word> Chapter::getWordsToStudy() {
    return toStudy;
};

Chapter::~Chapter() {
//    delete counter;
}