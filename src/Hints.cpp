//
// Created by My on 27.05.2022.
//

#include "../headers/Hints.h"
#include "windows.h"
#include <iostream>
#include <conio.h>
using namespace std;

Hints::Hints() {
    cout << "Hints constr" << endl;
}

string Hints::first_hint(English_Word word) {
    string writing;

    for(int i=0 ; i<word.get_length() ; i++) {
        if(i == 0 || i == word.get_length() -1) {
            writing += word.get_value()[i];
            writing += ' ';
        } else {
            writing += "_ ";
        }
    }

    return writing;
}

string Hints::second_hint(English_Word word) {
    string writing;

    if(word.get_length() < 5)
        return "<Word is too short>";

    for(int i=0 ; i<word.get_length() ; i++) {
        if(i == 0 || i == 1 || i == word.get_length() -1 || i == word.get_length() -2) {
            writing += word.get_value()[i];
            writing += ' ';
        } else {
            writing += "_ ";
        }
    }

    return writing;
}

void Hints::smooth_cout(std::string text)
{
    const int time = 20;
    for(int i=0; i<text.size(); i++)
    {
        cout<<text[i];
        Sleep(time);
    }
}

bool Hints::get_bool_input() {
    int hints;

    do{
        hints=_getche()-48;
        cout<<'\n';

        if(hints==1){
            cout << "Picked 1 (yes)";
        }

        else if(hints==0){
            cout << "Picked 0 (no) \n";
        }

        else{
            smooth_cout("	Choose 1 or 0 (again)\n");
        }
    }while(hints!=0 && hints!=1);

    return hints;
}

void Hints::handleHint(int incorrect, int hints, int hint_option, vector<English_Word> translations) {
    cout << "\n -- calculating which hint to give for " << incorrect << " incorrects, and " << hints << " hints ...\" -- \n";

    if(hint_option==1) {
        const string clb = first_hint(translations.front());
        smooth_cout(clb);

        if(translations.size() > 1) {
            for(auto word = translations.begin() +1; word != translations.end(); ++word){
                cout<<"	or	";
                smooth_cout(first_hint(*word));
            }
        }

        cout << endl;
    }
    else if(hint_option==2) {
        const string clb = second_hint(translations.front());
        smooth_cout(clb);

        if(translations.size() > 1) {
//        for(auto word : translations){
            for(auto word = translations.begin() +1; word != translations.end(); ++word){
                cout<<"	or	";
                smooth_cout(second_hint(*word));
            }
        }

        cout << endl;
    }
    else cout << endl << "                There is no option for configuration like that" << endl;
}

int Hints::ask_if_hint_needed(int count_incorrect, int hints) {
    bool answer;
    int option = 0;

    if (count_incorrect == 2 || (count_incorrect > 2 && hints == 0)) {
        //--------------first_hint_suggestion-----------------
        smooth_cout("Want a hint? \n");
        cout << "	1 - yes			0 - no \n";
        answer = get_bool_input();

        if (answer) option = 1;
    } else if (count_incorrect == 3 || (count_incorrect > 3 && hints == 1)) {
        //--------------second_hint_suggestion-----------------
        smooth_cout("	Do you want to get one more hint? \n");
        cout << "	1 - yes			0 - no \n";
        answer = get_bool_input();

        if (answer) option = 2;
    } else if (count_incorrect > 3 && hints == 2) {
        cout << "	skip? \n";
        cout << "	1 - yes			0 - no \n";
        answer = get_bool_input();

        if (answer) option = 3;
    }
    return option;
//    if(count_incorrect==2 || (count_incorrect>2 && hints==0)){
//        //--------------first_hint_suggestion-----------------
//      }
//    count_incorrect++;
//}
//else{
////-----------------count-final-scores------------
//if(count_incorrect==1){
//spot_on++;
//}
//
//else{
//corrected++;
//wordsToLearn[toLearnIndex]++;
//}
//
//cout<<"	correct\n\n";
//Sleep(175);
//system("CLS");
//}
}