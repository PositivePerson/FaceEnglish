//
// Created by My on 17.05.2022.
//

#ifndef UNTITLED_POLISH_WORD_H
#define UNTITLED_POLISH_WORD_H

#include "English_Word.h"
#include <vector>

class Polish_Word: public Word {
    std::vector<English_Word> mTranslations;
    int mIncorrect_ans = 0;
public:
    Polish_Word(std::string aArgValue, English_Word aEng_line);
    void info();
    int get_incorrect_num();
    void count_incorrect();
    std::vector<English_Word> get_translations();
    void reset_counters();
    void reset_translations_counters();

    void add_incorrect_eng();
    void operator= (const Polish_Word &aD );
};


#endif //UNTITLED_POLISH_WORD_H
