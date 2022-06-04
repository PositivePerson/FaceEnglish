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
    std::vector<Polish_Word> to_study;
    std::vector<Polish_Word> pl_word;
    std::vector<English_Word> eng_words;

    int lines_amount = 0;
//    int correct = 0;
//    int incorrect = 0;
//    int skipped = 0;
public:
    Counter counter;

    Chapter(std::string pl_name, std::string eng_name);
    ~Chapter();

    void info();
    void fetch_lines(std::string pl_name, std::string eng_name);
    int get_lines_amount();
//    int get_correct_num();
//    int get_incorrect_num();
//    int get_skipped_num();

//    std::string pl_file_name;
//    std::string eng_file_name;

    std::vector<Polish_Word> get_pl_words();
    std::vector<Polish_Word> get_words_to_study();

    void filter_to_incorrect();
    void set_word_to_study(Polish_Word *word);
    void reset_to_study();

//    friend Polish_Word operator+(Polish_Word const &a, Polish_Word const &b);
};


#endif //UNTITLED_CHAPTER_H
