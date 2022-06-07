//
// Created by My on 17.05.2022.
//

#include "../headers/Polish_Word.h"
#include <iostream>

using namespace std;

Polish_Word::Polish_Word(string aArgValue, English_Word aEng_line) {
        set_value(aArgValue);

        size_t position = 51;

        position = aEng_line.find("OR");
        do{
            position = aEng_line.find("OR");
//            cout << "--------position: " << position << endl;

            if(position<50){
                const string temp = aEng_line.substr(0, position - 1);
//                cout << "--------aEng_line after substr(): " << temp << endl;
                mTranslations.push_back(temp);
                aEng_line.erase(0, position + 3);

//                cout << "--------aEng_line after erase(): " << aEng_line.get_value() << endl;
            }
            else{
//                cout << "--------pushing to vector: " << aEng_line.get_value() << endl;
                mTranslations.push_back(aEng_line.get_value());
            }

        }while(position<50);

        for(English_Word i : mTranslations){
            cout << "mTranslations = " << i.get_value() << endl;
        }

        info();
}

void Polish_Word::info() {
    Word::info();

    cout << "mTranslations num: " << mTranslations.size() << endl;
}

int Polish_Word::get_incorrect_num() {
    return mIncorrect_ans;
}

void Polish_Word::count_incorrect() {
    mIncorrect_ans++;
}

std::vector<English_Word> Polish_Word::get_translations() {
    return mTranslations;
}

void Polish_Word::add_incorrect_eng() {
//    cout << "mTranslations[0] adress: " << &(mTranslations[0]) << endl;

    for(auto it = mTranslations.begin() ; it != mTranslations.end() ; ++it) {
//    for(auto word : mTranslations) {
//        cout << "mTranslations[i] adress (in loop): " << &(it) << "  |  " << &(*it) << endl;
        (*it).addIncorrect();
    }
}

void Polish_Word::operator=(const Polish_Word &aD) {
    mHints = aD.mHints;
    mLength = aD.mLength;
    mValue = aD.mValue;
    mTranslations = aD.mTranslations;
    mIncorrect_ans = aD.mIncorrect_ans;
}

void Polish_Word::reset_counters() {
    mIncorrect_ans = 0;
    reset_translations_counters();
}

void Polish_Word::reset_translations_counters() {
    for(auto it = mTranslations.begin() ; it != mTranslations.end() ; ++it) (*it).reset();
}
