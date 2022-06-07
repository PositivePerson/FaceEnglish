//
// Created by My on 27.05.2022.
//

#ifndef UNTITLED_HINTS_H
#define UNTITLED_HINTS_H

#include <vector>
#include "English_Word.h"
//#include "Console.h"

class Hints {
public:
    Hints();

    std::string firstHint(English_Word aWord);
    void handleHint(int aIncorrect, int aHints, int aHint_option, std::vector<English_Word> aTranslations);
    int askIfHintNeeded(int aCount_incorrect, int aHints);
    void smoothCout(std::string aText);
    bool getBoolInput();
    std::string second_hint(English_Word aWord);
};

#endif //UNTITLED_HINTS_H
