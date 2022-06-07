//
// Created by My on 29.05.2022.
//

#ifndef UNTITLED_COUNTER_H
#define UNTITLED_COUNTER_H


class Counter {
    int mCorrect = 0;
    int mIncorrect = 0;
    int mSkipped = 0;
public:
    void addCorrect();
    void addIncorrect();
    void addSkipped();

    int getCorrectNum();
    int getIncorrectNum();
    int getSkippedNum();

    void reset();

};


#endif //UNTITLED_COUNTER_H
