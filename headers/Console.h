//
// Created by My on 10.05.2022.
//

#ifndef UNTITLED_CONSOLE_H
#define UNTITLED_CONSOLE_H


#include <string>
#include "Chapter.h"

class Console {
    void smooth_cout(std::string text);
    bool get_bool_input();
    Chapter* current_chapter;
public:
    Console();
    ~Console();
    void welcome();
    void choose_chapter();
    void play();
    bool ask_if_hint_needed(int count_incorrect, int hints);


//    void smooth_cout(std::__cxx11::basic_string<char> text);
    const std::string get_user_answer();

    void cleanConsole();

    bool check_if_answer_match(std::string word, std::string answer);
};


#endif //UNTITLED_CONSOLE_H
