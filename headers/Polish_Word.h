//
// Created by My on 17.05.2022.
//

#ifndef UNTITLED_POLISH_WORD_H
#define UNTITLED_POLISH_WORD_H

#include "English_Word.h"
#include <vector>

//class Polish_Word:public Word {
class Polish_Word: public Word {
    unsigned int eng_equals = 0;
    bool taught = false;
    std::vector<English_Word> translations;
public:
//    Polish_Word(std::string eng_line);
    Polish_Word(std::string argValue, English_Word eng_line);
    void setTaught(bool val);
    std::vector<English_Word> get_translations();
};


#endif //UNTITLED_POLISH_WORD_H
