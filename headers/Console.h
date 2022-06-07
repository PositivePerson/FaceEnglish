//
// Created by My on 10.05.2022.
//

#ifndef UNTITLED_CONSOLE_H
#define UNTITLED_CONSOLE_H


#include <string>
#include "Chapter.h"
#include "Hints.h"
//#include "Counter.h"

class Console {
    Chapter* current_chapter;
    Hints* hint;
public:
    void smooth_cout(std::string text);
    Console();
    ~Console();
    void welcome();
    void choose_chapter();
    void play();

    const std::string get_user_answer();
    void clearConsole();
    bool check_if_answer_match(std::vector<English_Word> translations, std::string answer);

    void end_screen();

    char get_char_input();
};

#endif //UNTITLED_CONSOLE_H
