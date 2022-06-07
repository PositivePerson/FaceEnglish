//
// Created by My on 13.05.2022.
//

#ifndef UNTITLED_CHAPTER_H
#define UNTITLED_CHAPTER_H


#include <string>
#include <vector>
#include "English_Word.h"
#include "Polish_Word.h"
#include "Counter.h"

class Chapter {
    std::vector<Polish_Word> toStudy;
    std::vector<Polish_Word> plWord;
    std::vector<English_Word> engWords;

    int linesAmount = 0;
public:
    Counter counter;

    Chapter(std::string aPlName, std::string aEngName);
    ~Chapter();

    void info();
    void fetchLines(std::string aPlName, std::string aEngName);
    int getLinesAmount();
    void filterToIncorrect();
    void setWordToStudy(Polish_Word *aWord);
    void resetToStudy();
    std::vector<Polish_Word> getPlWords();
    std::vector<Polish_Word> getWordsToStudy();
};


#endif //UNTITLED_CHAPTER_H
