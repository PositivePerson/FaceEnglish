//
// Created by My on 17.05.2022.
//

#include "../headers/Polish_Word.h"
#include <iostream>

using namespace std;

Polish_Word::Polish_Word(string argValue, English_Word eng_line) {
        set_value(argValue);

        size_t position = 51;

        position = eng_line.find("OR");
        do{
            position = eng_line.find("OR");
//            cout << "--------position: " << position << endl;

            if(position<50){
                const string temp = eng_line.substr(0, position-1);
//                cout << "--------eng_line after substr(): " << temp << endl;
                translations.push_back(temp);
                eng_line.erase(0, position+3);

//                cout << "--------eng_line after erase(): " << eng_line.get_value() << endl;
            }
            else{
//                cout << "--------pushing to vector: " << eng_line.get_value() << endl;
                translations.push_back(eng_line.get_value());
            }

        }while(position<50);

        for(English_Word i : translations){
            cout << "translations = " << i.get_value() << endl;
        }

        eng_equals = translations.size();

        info();
}

void Polish_Word::info() {
    Word::info();

    cout << "translations num: " << translations.size() << endl;
}


void Polish_Word::setTaught(bool val) {
    taught = val;
}

int Polish_Word::get_incorrect_num() {
    return incorrect_ans;
}

void Polish_Word::count_incorrect() {
    incorrect_ans++;
}

//void Polish_Word::set_fault() {
//    if(faultless) faultless = false;
//}

std::vector<English_Word> Polish_Word::get_translations() {
    return translations;
}

void Polish_Word::add_incorrect_eng() {
//    cout << "translations[0] adress: " << &(translations[0]) << endl;

    for(auto it = translations.begin() ; it != translations.end() ; ++it) {
//    for(auto word : translations) {
//        cout << "translations[i] adress (in loop): " << &(it) << "  |  " << &(*it) << endl;
        (*it).add_incorrect();
    }
}

void Polish_Word::operator=(const Polish_Word &WRD) {
    hints = WRD.hints;
    length = WRD.length;
    value = WRD.value;
    translations = WRD.translations;
    incorrect_ans = WRD.incorrect_ans;
}

void Polish_Word::reset_translations_counters() {
    for(auto it = translations.begin() ; it != translations.end() ; ++it) (*it).reset();
}
