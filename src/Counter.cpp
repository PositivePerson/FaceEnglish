//
// Created by My on 29.05.2022.
//

#include "../headers/Counter.h"

void Counter::add_correct() {
    correct++;
}

void Counter::add_incorrect() {
    incorrect++;
}

void Counter::add_skipped() {
    skipped++;
}

int Counter::get_correct_num() {
    return correct;
}

int Counter::get_incorrect_num() {
    return incorrect;
}

int Counter::get_skipped_num() {
    return skipped;
}

void Counter::reset() {
    incorrect = 0;
    correct = 0;
    skipped = 0;
}