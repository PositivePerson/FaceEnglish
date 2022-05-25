//
// Created by My on 10.05.2022.
//

#include "../headers/Console.h"
#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <algorithm>
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
    cout<<"   4 - Test"<<'\n';
//    cout<<"   4 - KitchenWare"<<'\n';
//    cout<<"   5 - People"<<'\n';
//    cout<<"   6 - Blended"<<'\n';
//    cout<<"   7 - Bank"<<'\n';
    cout<<"			Ending round: 'end'\n	";
    cout<<"		Exit: 'exit'\n	";
}

int Console::ask_if_hint_needed(int count_incorrect, int hints) {
    bool answer;
    int option = 0;

    if(count_incorrect==2 || (count_incorrect>2 && hints==0)){
        //--------------first_hint_suggestion-----------------
        smooth_cout("Want a hint? \n");
        cout<<"	1 - yes			0 - no \n";
        answer = get_bool_input();

        if(answer) option = 1;
    }
    else if(count_incorrect==3 || (count_incorrect>3 && hints==1)) {
        //--------------second_hint_suggestion-----------------
        smooth_cout("	Do you want to get one more hint? \n");
        cout<<"	1 - yes			0 - no \n";
        answer = get_bool_input();

        if(answer) option = 2;
    }
    else if(count_incorrect>3 && hints==2) {
        cout << "	skip? \n";
        cout << "	1 - yes			0 - no \n";
        answer = get_bool_input();

        if(answer) option = 3;
    }
    return option;
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
                eng_file="engFamily.txt";
                pl_file="polFamily.txt";
                break;
            case 2:
                eng_file="engHome.txt";
                pl_file="polHome.txt";
                break;
            case 3:
                eng_file="engInHouse.txt";
                pl_file="polInHouse.txt";
                break;
            case 4:
                eng_file="engTest.txt";
                pl_file="polTest.txt";
                break;
//            case 4:
//                eng_file="engKitchenWare.txt";
//                pl_file="polKitchenWare.txt";
//                break;
//            case 5:
//                eng_file="English_words_part_1.txt";
//                pl_file="Polish_words_part_1.txt";
//                break;
//            case 6:
//                eng_file="English_words_part_2.txt";
//                pl_file="Polish_words_part_2.txt";
//                break;
//            case 7:
//                eng_file="eng_people.txt";
//                pl_file="pol_people.txt";
//                break;
            default:
                cout<<"Mistake in command\n	";
                continue;
        }
    }while(whichSubject<1 || whichSubject>7);

    current_chapter = new Chapter(pl_file, eng_file);

    play();
}

bool Console::get_bool_input() {
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

void Console::play() {
//    for(int i = 0 ; i < current_chapter->get_lines_amount() ; ++i){
    for(auto word : current_chapter->pl_word){
//        clearConsole();

        cout << word.get_value() << " to po angielsku: \n" ;
        string user_ans;
        bool correct = false;

        do{
            user_ans = get_user_answer();
            correct = check_if_answer_match(word.get_translations(), user_ans);

            if(!correct) {
                const int hint_option = ask_if_hint_needed(word.get_incorrect_num(), word.get_hints_num());

                cout << "\n word.get_incorrect_num() : " << word.get_incorrect_num() << " \n word.get_hints_num(): " << word.get_hints_num() << "\n";
                if(hint_option > 0) {
//                    cout << "The hint is ... \n*dead* \n";
                    handleHint(word.get_incorrect_num(), word.get_hints_num(), hint_option, word.get_translations());

                    word.count_hints();
                }

                word.count_incorrect();
            } else if(correct) {
                cout << "That's right answer! \n";
                system("PAUSE");
            }
        } while (!correct);
    }
}

const string Console::get_user_answer() {
    string answer = "";
    cin >> answer;

    if(answer == "exit") {
        cout << "Typed in \"exit\" \n";
        _Exit(0);
    } else if(answer == "end")
        cout << "Typed in \"end\" \n";
    return answer;
}

void Console::clearConsole() {
    Sleep(200);
    system("CLS");
}

bool Console::check_if_answer_match(vector<English_Word> translations, string answer ) {
    bool matched = false;

    cout << "\n ================ \n " << "check_if_answer_match\n" ;
    for(auto i : translations){
        cout << "word: " << i.get_value() << "\nanswer: " << answer << "\n" ;

        if(i.get_value() == answer){
            matched = true;
            break;
        }
    }
    cout << "================ \n " ;

    return matched;
}

void Console::handleHint(int incorrect, int hints, int hint_option, vector<English_Word> translations) {
    cout << "\n -- calculating which hint to give for " << incorrect << " incorrects, and " << hints << " hints ...\" -- \n";

            if(hint_option==1) {
//                firstHint(translations.front());
//                    if(translations.size() > 1) {
                        for(auto word : translations){
                            firstHint(word);
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

void Console::firstHint(English_Word word) {
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

    smooth_cout(writing);
}

Console::~Console() {
    delete current_chapter;
}
