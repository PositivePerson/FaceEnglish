//
// Created by My on 27.05.2022.
//

#include "../headers/Hints.h"
#include "windows.h"
#include <iostream>
#include <conio.h>
using namespace std;

Hints::Hints() {
//    cout << "Hints constr" << endl;
}

string Hints::firstHint(English_Word aWord) {
    string writing;

    for(int i=0 ; i < aWord.get_length() ; i++) {
        if(i == 0 || i == aWord.get_length() - 1) {
            writing += aWord.get_value()[i];
            writing += ' ';
        } else {
            writing += "_ ";
        }
    }

    return writing;
}

string Hints::second_hint(English_Word aWord) {
    string writing;

    if(aWord.get_length() < 5)
        return "<Word is too short>";

    for(int i=0 ; i < aWord.get_length() ; i++) {
        if(i == 0 || i == 1 || i == aWord.get_length() - 1 || i == aWord.get_length() - 2) {
            writing += aWord.get_value()[i];
            writing += ' ';
        } else {
            writing += "_ ";
        }
    }

    return writing;
}

void Hints::smoothCout(std::string aText)
{
    const int time = 20;
    for(int i=0; i < aText.size(); i++)
    {
        cout << aText[i];
        Sleep(time);
    }
}

bool Hints::getBoolInput() {
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
            smoothCout("	Choose 1 or 0 (again)\n");
        }
    }while(hints!=0 && hints!=1);

    return hints;
}

void Hints::handleHint(int aIncorrect, int aHints, int aHint_option, vector<English_Word> aTranslations) {
    cout << "\n -- calculating which mHint to give for " << aIncorrect << " incorrects, and " << aHints << " aHints ...\" -- \n";

    if(aHint_option == 1) {
        const string clb = firstHint(aTranslations.front());
        smoothCout(clb);

        if(aTranslations.size() > 1) {
            for(auto word = aTranslations.begin() + 1; word != aTranslations.end(); ++word){
                cout<<"	or	";
                smoothCout(firstHint(*word));
            }
        }

        cout << endl;
    }
    else if(aHint_option == 2) {
        const string clb = second_hint(aTranslations.front());
        smoothCout(clb);

        if(aTranslations.size() > 1) {
//        for(auto word : aTranslations){
            for(auto word = aTranslations.begin() + 1; word != aTranslations.end(); ++word){
                cout<<"	or	";
                smoothCout(second_hint(*word));
            }
        }

        cout << endl;
    }
    else cout << endl << "                There is no option for configuration like that" << endl;
}

int Hints::askIfHintNeeded(int aCount_incorrect, int aHints) {
    bool answer;
    int option = 0;

    if (aCount_incorrect == 2 || (aCount_incorrect > 2 && aHints == 0)) {
        //--------------first_hint_suggestion-----------------
        smoothCout("Want a mHint? \n");
        cout << "	1 - yes			0 - no \n";
        answer = getBoolInput();

        if (answer) option = 1;
    } else if (aCount_incorrect == 3 || (aCount_incorrect > 3 && aHints == 1)) {
        //--------------second_hint_suggestion-----------------
        smoothCout("	Do you want to get one more mHint? \n");
        cout << "	1 - yes			0 - no \n";
        answer = getBoolInput();

        if (answer) option = 2;
    } else if (aCount_incorrect > 3 && aHints == 2) {
        cout << "	skip? \n";
        cout << "	1 - yes			0 - no \n";
        answer = getBoolInput();

        if (answer) option = 3;
    }
    return option;
//    if(aCount_incorrect==2 || (aCount_incorrect>2 && aHints==0)){
//        //--------------first_hint_suggestion-----------------
//      }
//    aCount_incorrect++;
//}
//else{
////-----------------count-final-scores------------
//if(aCount_incorrect==1){
//spot_on++;
//}
//
//else{
//corrected++;
//wordsToLearn[toLearnIndex]++;
//}
//
//cout<<"	mCorrect\n\n";
//Sleep(175);
//system("CLS");
//}
}