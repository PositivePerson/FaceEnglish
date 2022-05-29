//
// Created by My on 29.05.2022.
//

#ifndef UNTITLED_COUNTER_H
#define UNTITLED_COUNTER_H


class Counter {
    int correct = 0;
    int incorrect = 0;
    int skipped = 0;
public:
    void add_correct();
    void add_incorrect();
    void add_skipped();

    int get_correct_num();
    int get_incorrect_num();
    int get_skipped_num();

    void reset();

};


#endif //UNTITLED_COUNTER_H
