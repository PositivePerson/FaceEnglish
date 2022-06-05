//
// Created by My on 17.05.2022.
//

#ifndef UNTITLED_ENGLISH_WORD_H
#define UNTITLED_ENGLISH_WORD_H


#include <vector>
#include "Word.h"

class English_Word: public Word {
    int tried_times = 0;
public:
    using Word::Word;
    void reset();
    std::string substr(int start, int end);
    void erase(int start, int end);
    size_t find(std::string phrase);
    friend std::ostream& operator<<(std::ostream &os, English_Word &D);
    friend English_Word operator+ (English_Word B, English_Word &D);

    void add_incorrect();
};


#endif //UNTITLED_ENGLISH_WORD_H
