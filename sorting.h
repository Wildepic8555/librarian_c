//
// Created by wildepic on 2/1/26.
//

#ifndef LIBRARIAN_SORTING_H
#define LIBRARIAN_SORTING_H

struct sortingParameter {
    char author[21];
    char title[21];
    char publisher[21];
    int year;
    char department[21];
};

struct bookData *sort(struct bookData *arrayToBeSorted , struct  sortingParameter sortingParameter);

#endif //LIBRARIAN_SORTING_H