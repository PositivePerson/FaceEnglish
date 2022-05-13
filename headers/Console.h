//
// Created by My on 10.05.2022.
//

#ifndef UNTITLED_CONSOLE_H
#define UNTITLED_CONSOLE_H


#include <string>
#include "Chapter.h"

class Console {
    void smooth_cout(std::string text);
    bool getBoolInput();
    Chapter* current_chapter;
public:
    Console();
    ~Console();
    void welcome();
    void choose_chapter();
    bool ask_id_hint_needed(int count_incorrect, int hints);


//    void smooth_cout(std::__cxx11::basic_string<char> text);
};


#endif //UNTITLED_CONSOLE_H
