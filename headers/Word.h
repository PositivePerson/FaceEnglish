//
// Created by My on 13.05.2022.
//

#ifndef UNTITLED_WORD_H
#define UNTITLED_WORD_H

#include <string>

class Word {
    int hints = 0;
    unsigned int length;
//    std::string value;
    int incorrect_ans = 0;
public:
    std::string value = "abc";

    Word();
    Word(std::string a);
    void info();
    std::string get_value();
    void count_incorrect();
    void count_hints();
    int get_incorrect_num();
    int get_hints_num();
    void set_value(std::string argValue);
};

#endif //UNTITLED_WORD_H
