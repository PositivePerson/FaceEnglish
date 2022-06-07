//
// Created by My on 29.05.2022.
//

#include "../headers/Counter.h"

void Counter::addCorrect() {
    mCorrect++;
}

void Counter::addIncorrect() {
    mIncorrect++;
}

void Counter::addSkipped() {
    mSkipped++;
}

int Counter::getCorrectNum() {
    return mCorrect;
}

int Counter::getIncorrectNum() {
    return mIncorrect;
}

int Counter::getSkippedNum() {
    return mSkipped;
}

void Counter::reset() {
    mIncorrect = 0;
    mCorrect = 0;
    mSkipped = 0;
}