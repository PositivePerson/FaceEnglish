//
// Created by My on 17.05.2022.
//

#include "../headers/Polish_Word.h"
#include <iostream>
using namespace std;

Polish_Word::Polish_Word(string argValue, English_Word eng_line) {
//Polish_Word::Polish_Word(string eng_line) {
//    void Chapter::divide_words(string line) {
//        vector<string> temp;
        set_value(argValue);

        std::size_t position = 51;

        do{
            position = eng_line.find("OR");

            cout << "--------position: " << position << endl;
            if(position<50){
                const string temp = eng_line.substr(0, position-1);
                cout << "--------eng_line after substr(): " << temp << endl;
                translations.push_back(temp);
                eng_line.erase(0, position+3);

                cout << "--------eng_line after erase(): " << eng_line.get_value() << endl;
            }
            else{
                translations.push_back(eng_line);
            }
        }while(position<50);

        for(English_Word i : translations){
            cout << "translations = " << i.get_value() << endl;
        }

        eng_equals = translations.size();
}

void Polish_Word::setTaught(bool val) {
    taught = val;
}
