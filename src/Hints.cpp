//
// Created by My on 27.05.2022.
//

#include "../headers/Hints.h"
#include "../headers/Console.h"
#include <iostream>
using namespace std;

Hints::Hints() {
    cout << "Hints constr" << endl;
}

//Hints::Hints(auto smooth_cout) {
//    cout << "Hints constr" << endl;
//}

string Hints::first_hint(English_Word word) {
    string writing;

//    cout << endl << "*IN firstHint FUNCTION                         (length: " << word.get_length() << ")" << endl;
    for(int i=0 ; i<word.get_length() ; i++) {
        if(i == 0 || i == word.get_length() -1) {
            writing += "_ ";
        } else {
//            cout << "word.get_value()[i] : " << word.get_value()[i] << endl;
            writing += word.get_value()[i];
            writing += ' ';
        }
    }
//    cout << "*OUT firstHint FUNCTION" << endl;

    return writing;
}

void Hints::handleHint(int incorrect, int hints, int hint_option, vector<English_Word> translations) {
    cout << "\n -- calculating which hint to give for " << incorrect << " incorrects, and " << hints << " hints ...\" -- \n";

    if(hint_option==1) {
//                firstHint(translations.front());
//                    if(translations.size() > 1) {
        for(auto word : translations){
//            smooth_cout(first_hint(word));
            cout << first_hint(word);
            cout<<"	or	";
        }
//                    }
    }
    else cout << endl << "                There is no option for configuration like that" << endl;
//                else if(hint_option==2){
//                secondHint(currentEngWord, 0, globalUnveils, globalLetters);
//
//                if(answers>1)
//                    for(int i=1;i<answers;i++){
//                        cout<<"	or	";
//                        secondHint(currentEngWord, i, globalUnveils, globalLetters);
//                    }
//
//                cout<<'\n';
//            } else if(hint_option==3){
//                secondHint(currentEngWord, 0, globalUnveils, globalLetters);
//
//                if(answers>1)
//                    for(int i=1;i<answers;i++){
//                        cout<<"	or	";
//                        secondHint(currentEngWord, i, globalUnveils, globalLetters);
//                    }
//
//                cout<<'\n';
//            }
//                            )
}