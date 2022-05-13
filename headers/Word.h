//
// Created by My on 13.05.2022.
//

#ifndef UNTITLED_WORD_H
#define UNTITLED_WORD_H

#include <string>

class Word {
    int hints = 0;
    int length;
    std::string value;
    int count_incorrect = 0;
public:
    Word(std::string a);
    void info();
};

#endif //UNTITLED_WORD_H
