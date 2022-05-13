//
// Created by My on 10.05.2022.
//

#include "../headers/Console.h"
#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
using namespace std;

Console::Console()
{
    cout << "- First constructor (Console) - \n";
}

void Console::smooth_cout(std::string text)
{
    const int time = 20;
    for(int i=0; i<text.size(); i++)
    {
        cout<<text[i];
        Sleep(time);
    }
}

void Console::welcome() {
    cout<<'\n';
    const string text="Choose subject:";
    smooth_cout("Choose subject:");
    cout<<"\n\n";
    cout<<"   1 - Family"<<'\n';
    cout<<"   2 - Home"<<'\n';
    cout<<"   3 - In the house"<<'\n';
    cout<<"   4 - KitchenWare"<<'\n';
    cout<<"   5 - People"<<'\n';
    cout<<"   6 - Blended"<<'\n';
    cout<<"   7 - Bank"<<'\n';
    cout<<"			Ending round: 'end'\n	";
    cout<<"		Exit: 'exit'\n	";
}

bool Console::ask_id_hint_needed(int count_incorrect, int hints) {
    bool answer;

    if(count_incorrect==2 || (count_incorrect>2 && hints==0)){
        //--------------first_hint_suggestion-----------------
        smooth_cout("Want a hint?");
        cout<<"	1 - yes			0 - no\n";
        answer = getBoolInput();
    }
    else if(count_incorrect==3 || (count_incorrect>3 && hints==1)) {
        //--------------second_hint_suggestion-----------------
        smooth_cout("	Do you want to get one more hint?\n");
        cout<<"	1 - yes			0 - no\n";
        answer = getBoolInput();
    }
    else if(count_incorrect>3 && hints==2) {
        cout << "	skip?\n";
        cout << "	1 - yes			0 - no\n";
        answer = getBoolInput();
    }
    return answer;
//    if(count_incorrect==2 || (count_incorrect>2 && hints==0)){
//        //--------------first_hint_suggestion-----------------
//        smooth_cout("	Do you want to get a hint?\n");
//
//        cout<<"	1 - yes			0 - no\n";
//
//        do{
//            cout<<"	";
//            hints=_getche()-48;
//            cout<<'\n';
//
//            if(hints==1){
//                firstHint(currentEngWord, 0, globalUnveils, globalLetters);
//
//                if(answers>1)
//                    for(int i=1;i<answers;i++){
//                        cout<<"	or	";
//                        firstHint(currentEngWord, i, globalUnveils, globalLetters);
//                    }
//
//                cout<<'\n';
//            }
//
//            else if(hints==0){
//
//            }
//
//            else{
//                smooth_cout("	Choose 1 or 0 (again)\n");
//            }
//
//        }while(hints!=0 && hints!=1);
//    }
//
//    else if(count_incorrect==3 || (count_incorrect>3 && hints==1)){
//        //--------------second_hint_suggestion-----------------
//        smooth_cout("	Do you want to get one more hint?\n");
//
//        cout<<"	1 - yes			0 - no\n";
//
//        do{
//            cout<<"	";
//            hints=_getche()-47;
//            cout<<'\n';
//
//            if(hints==2){
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
//
//            else if(hints==1){
//
//            }
//
//            else{
//                smooth_cout("	Choose 1 or 0 (again)\n");
//            }
//
//        }while(hints!=1 && hints!=2);
//    }
//
//    else if(count_incorrect>3 && hints==2){
//        cout<<"	skip?\n";
//        cout<<"	1 - yes			0 - no\n";
//
//        do{
//            cout<<"	";
//            hints=_getche()-46;
//            cout<<'\n';
//
//            if(hints==3){
//                blanks++;
//                wordsToLearn[toLearnIndex]++;
//                for(int i=0;i<answers;i++) cout<<"	"<<currentEngWord[i]<<'\n';
//                Sleep(500);
//                system("CLS");
//                goto surrender;
//            }
//
//            else if(hints==2){
//                //hints=1;
//            }
//
//            else{
//                smooth_cout("	Yes(1) or No(0)\n");
//            }
//
//        }while(hints!=2 && hints!=3);
//    }
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

void Console::choose_chapter() {
    int whichSubject=0;
    string eng_file;
    string pl_file;

    do{
        cin>>whichSubject;
        //whichSubject=_getche()-48;

        switch(whichSubject){
            case 1:
                eng_file="engFamilyCoded.txt";
                pl_file="polFamilyCoded.txt";
                break;
            case 2:
                eng_file="engHomeCoded.txt";
                pl_file="polHomeCoded.txt";
                break;
            case 3:
                eng_file="engInHouseCoded.txt";
                pl_file="polInHouseCoded.txt";
                break;
            case 4:
                eng_file="engKitchenWareCoded.txt";
                pl_file="polKitchenWareCoded.txt";
                break;
            case 5:
                eng_file="English_words_part_1.txt";
                pl_file="Polish_words_part_1.txt";
                break;
            case 6:
                eng_file="English_words_part_2.txt";
                pl_file="Polish_words_part_2.txt";
                break;
            case 7:
                eng_file="eng_people.txt";
                pl_file="pol_people.txt";
                break;
            default:
                cout<<"Mistake in command\n	";
                continue;
        }
    }while(whichSubject<1 || whichSubject>7);

    current_chapter = new Chapter(pl_file, eng_file);
}

bool Console::getBoolInput() {
    int hints;
    do{
//            cout<<"	";
            hints=_getche()-48;
            cout<<'\n';

            if(hints==1){
                cout << "Picked 1 (yes)";
                cout << "<First Hint> \n";
//                firstHint(currentEngWord, 0, globalUnveils, globalLetters);
//
//                if(answers>1)
//                    for(int i=1;i<answers;i++){
//                        cout<<"	or	";
//                        firstHint(currentEngWord, i, globalUnveils, globalLetters);
//                    }
//
//                cout<<'\n';
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

Console::~Console() {
    delete current_chapter;
}
