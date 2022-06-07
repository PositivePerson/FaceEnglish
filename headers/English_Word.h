//
// Created by My on 17.05.2022.
//

#ifndef UNTITLED_ENGLISH_WORD_H
#define UNTITLED_ENGLISH_WORD_H


#include <vector>
#include "Word.h"

class English_Word: public Word {
    int mTriedTimes = 0;
public:
    using Word::Word;
    void reset();
    std::string substr(int aStart, int aEnd);
    void erase(int aStart, int aEnd);
    size_t find(std::string aPhrase);
    void addIncorrect();
    friend std::ostream& operator<<(std::ostream &aOs, English_Word &aD);
    friend English_Word operator+ (English_Word aB, English_Word &aD);
};


#endif //UNTITLED_ENGLISH_WORD_H
