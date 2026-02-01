//
// Created by wildepic on 2/1/26.
//

#ifndef LIBRARIAN_SORTING_H
#define LIBRARIAN_SORTING_H

struct sortingParameter {
    char author[50];
    char title[50];
    char publisher[50];
    int year;
    char department[25];
};

struct bookData *sort(struct bookData *arrayToBeSorted , struct  sortingParameter sortingParameter);

#endif //LIBRARIAN_SORTING_H