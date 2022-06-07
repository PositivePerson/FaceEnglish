//
// Created by My on 13.05.2022.
//

#ifndef UNTITLED_WORD_H
#define UNTITLED_WORD_H

#include <string>

class Word {
protected:
    int mHints = 0;
    unsigned int mLength;
    std::string mValue;
public:
    Word();
    Word(std::string a);
    virtual void info();
    std::string get_value();
    int get_hints_num();
    int get_length();
    void count_hints();
    void set_value(std::string aArgValue);
};

#endif //UNTITLED_WORD_H
