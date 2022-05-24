//
// Created by My on 13.05.2022.
//

#ifndef UNTITLED_CHAPTER_H
#define UNTITLED_CHAPTER_H


#include <string>
#include <vector>
#include "English_Word.h"
#include "Polish_Word.h"

class Chapter {
    std::vector<Polish_Word> to_study;
    std::vector<English_Word> eng_words;

    int lines_amount = 0;
    int correct = 0;
    int incorrect = 0;
public:
    Chapter(std::string pl_name, std::string eng_name);
    void reset_counters();
    void fetch_lines(std::string pl_name, std::string eng_name);
    void divide_words(std::string line);
    int get_lines_amount();

    void info();

//    std::string pl_file_name;
//    std::string eng_file_name;
//    std::vector<std::string> pl_word;
    std::vector<Polish_Word> pl_word;
};


#endif //UNTITLED_CHAPTER_H
