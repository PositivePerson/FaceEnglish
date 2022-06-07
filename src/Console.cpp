//
// Created by My on 10.05.2022.
//

#include "../headers/Console.h"
#include <iostream>
#include "windows.h"
#include <conio.h>
#include <algorithm>
using namespace std;

Console::Console()
{
//    cout << "- First constructor (Console) - \n";
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
//    cout<<"   5 - KitchenWare"<<'\n';
//    cout<<"   5 - People"<<'\n';
//    cout<<"   6 - Blended"<<'\n';
//    cout<<"   7 - Bank"<<'\n';
    cout<<"			User commands available:\n	";
    cout<<"			Ending round: 'end'\n	";
    cout<<"		Exit: 'exit'\n	";
}

void Console::choose_chapter() {
    int whichSubject=0;
    string eng_file;
    string pl_file;

    do{
//        cin>>whichSubject;
        whichSubject=get_char_input() -48;

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
//            case 5:
//                eng_file="endKitchenWare.txt";
//                pl_file="polKitchenWare.txt";
//                break;
//            case 6:
//                eng_file="engKitchenWare.txt";
//                pl_file="polKitchenWare.txt";
//                break;
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
    hint = new Hints();

    play();
}

void Console::play() {
    for(auto word : current_chapter->get_pl_words()){
        clearConsole();

        cout << word.get_value() << " to po angielsku: " << endl ;
        string user_ans;
        bool correct = false;

        int hint_option;
        do{
            user_ans = get_user_answer();
            correct = check_if_answer_match(word.get_translations(), user_ans);

            if(!correct) {
                word.add_incorrect_eng();
            }
            if(!correct && word.get_incorrect_num() < 2) {
                cout << "Try again:" << endl;
                word.count_incorrect();
            }
            else if(!correct) {
                hint_option = hint->ask_if_hint_needed(word.get_incorrect_num(), word.get_hints_num());

                if(hint_option == 3) {
                    current_chapter->counter.add_skipped();
                    break;
                }

                else if(hint_option > 0) {
                    hint->handleHint(word.get_incorrect_num(), word.get_hints_num(), hint_option,  word.get_translations());

                    word.count_hints();
                }

                word.count_incorrect();
            } else if(correct) {
                cout << "That's right!" << endl;

                Sleep(500);
            }
        } while (!correct);

        if(word.get_incorrect_num() == 0) {
            current_chapter->counter.add_correct();
        }
        else {
//            cout << "Original obj destination: " << &(word.get_translations()[0]) << endl;
            current_chapter->set_word_to_study(&word);

            if(hint_option != 3) {
                current_chapter->counter.add_incorrect();
            }
        }
    }

    end_screen();
}

const string Console::get_user_answer() {
    string answer = "";
//    cin >> answer;
    getline(cin, answer);

    if(answer == "exit") {
        cout << "Typed in \"exit\" \n";
        _Exit(0);
    }
    else if(answer == "end") {
        cout << "Typed in \"end\" \n";

          clearConsole();
            end_screen();
            system("PAUSE");
            _Exit(0);
    }
    else
        return answer;
}

void Console::clearConsole() {
    Sleep(200);
    system("CLS");
}

bool Console::check_if_answer_match(vector<English_Word> translations, string answer ) {
    bool matched = false;

    cout << endl << "==== check_if_answer_match ====" << endl ;
    cout << "words: ";
    for(auto i : translations){
        cout << i.get_value() << ", ";

        if(i.get_value() == answer){
            matched = true;
            break;
        }
    }
    cout << endl << "answer: " << answer << endl ;
    cout << "============================ \n " ;

    return matched;
}

void Console::end_screen(){

    clearConsole();

    cout << endl;
    cout<<" Spot-on: "<<current_chapter->counter.get_incorrect_num() << endl;
    cout<<" Faultless: "<< current_chapter->counter.get_correct_num() << endl;
    cout<<" Skipped: "<< current_chapter->counter.get_skipped_num() << endl;
    cout<<" From: "<< current_chapter->get_lines_amount() << " words" << endl;
    cout<< endl << endl;

    smooth_cout(" Words to learn:");
    cout << endl;

    for(auto word : current_chapter->get_words_to_study()){
//        const string temp = word.get_value();
//        cout << temp;
//        cout << endl;

        if(word.get_translations().size() == 1) cout << word.get_translations()[0] << endl;
        else {
            English_Word temp = word.get_translations()[0];

            for(auto it = word.get_translations().begin() +1 ; it != word.get_translations().end() ; ++it) {
                temp = temp + (*it);
            }

            cout << temp << endl;
        }
    }

    cout << endl;
    if(current_chapter->get_lines_amount() == current_chapter->get_pl_words().size()) cout<<"	1 - face all again		";
    if(current_chapter->counter.get_incorrect_num() > 0 || current_chapter->counter.get_skipped_num() > 0) cout << "2 - face described words";
    cout << "		3 - exit";
    cout << endl;

    char input = get_char_input();

//        clearConsole();
    if(input == '1'){
        current_chapter->reset_to_study();
        current_chapter->counter.reset();
        play();
    }

    if(input == '2'){
        current_chapter->filter_to_incorrect();
        current_chapter->counter.reset();
        play();
    }

    if(input == '3'){
        smooth_cout("See ya");
        cout << endl;

        system("PAUSE");
        _Exit(0);
    }
}

char Console::get_char_input() {
    char choice;

    do{
        choice=_getche();
    }while(choice<'1' || choice>'3');
    cout << endl;

    return choice;
}

Console::~Console() {
    cout << "--------------- C O N S O L E       D E S T R U C T O R ---------------";

    delete current_chapter;
    delete hint;
}
