//
// Created by My on 13.05.2022.
//

#ifndef UNTITLED_CHAPTER_H
#define UNTITLED_CHAPTER_H


#include <string>
#include <vector>

class Chapter {
//    std::string pl_file_name;
//    std::string eng_file_name;
    std::vector<std::string> pl_words;
    std::vector<std::string> eng_words;

    int lines_amount;
    int correct = 0;
    int incorrect = 0;
public:
    Chapter(std::string pl_name, std::string eng_name);
    void reset_counters();
    void fetch_lines(std::string pl_name, std::string eng_name);
    void divide_words();

    void info();
};


#endif //UNTITLED_CHAPTER_H
