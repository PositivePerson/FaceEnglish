//
// Created by My on 10.05.2022.
//

#ifndef UNTITLED_CONSOLE_H
#define UNTITLED_CONSOLE_H


#include <string>
#include "Chapter.h"
#include "Hints.h"
//#include "Counter.h"

class Console {
    Chapter* mCurrentChapter;
    Hints* mHint;
public:
    void smoothCout(std::string aText);
    Console();
    ~Console();
    void welcome();
    void chooseChapter();
    void play();
    const std::string getUserAnswer();
    void clearConsole();
    bool checkIfAnswerMatch(std::vector<English_Word> aTranslations, std::string aAnswer);
    void endScreen();
    char getCharInput();
};

#endif //UNTITLED_CONSOLE_H
