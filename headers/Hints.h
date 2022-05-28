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

    Hints(std::string argValue, English_Word eng_line);

    std::string first_hint(English_Word word);

    void handleHint(int incorrect, int hints, int hint_option, std::vector<English_Word> translations);

    int ask_if_hint_needed(int count_incorrect, int hints);

    void smooth_cout(std::string text);

    bool get_bool_input();

    std::string second_hint(English_Word word);
};

#endif //UNTITLED_HINTS_H
