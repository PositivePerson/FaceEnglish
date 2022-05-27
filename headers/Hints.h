//
// Created by My on 27.05.2022.
//

#ifndef UNTITLED_HINTS_H
#define UNTITLED_HINTS_H

#include <vector>
#include "English_Word.h"

class Hints {
public:
    Hints();

    Hints(std::string argValue, English_Word eng_line);

    std::string first_hint(English_Word word);

    void handleHint(int incorrect, int hints, int hint_option, std::vector<English_Word> translations);
};

#endif //UNTITLED_HINTS_H
