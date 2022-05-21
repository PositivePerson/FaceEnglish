//
// Created by My on 17.05.2022.
//

#ifndef UNTITLED_ENGLISH_WORD_H
#define UNTITLED_ENGLISH_WORD_H


#include "Word.h"

class English_Word: public Word {
    int tried_times = 0;
public:
//    English_Word();
    using Word::Word;
    int get_tried_times();
    void substr(int start, int end);
    void erase(int start, int end);
    size_t find(std::string phrase);
};


#endif //UNTITLED_ENGLISH_WORD_H
