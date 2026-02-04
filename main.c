#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "readBook.h"
#include "showBooks.h"
#include "sorting.h"

void clearSortParameter(struct sortingParameter *array);

int main(void) {
    //init the bookarray and also reads the values into it
    struct bookData *bookArray = malloc(arrayLength *sizeof(struct bookData));
    struct sortingParameter sortParam;

    //Clear residue were now the sorting parameters are
    clearSortParameter(&sortParam);

    /*
    //Test
    sortParam.author[0] = 'w';
    sortParam.author[1] = 'i';
    sortParam.title[0] = 'c';
    sortParam.title[1] = 'e';
    sortParam.publisher[0] = 'w';
    sortParam.publisher[1] = 'i';
    sortParam.year = 0;
    sortParam.department[0] = 'a';
    sortParam.department[1] = 'l';
    */

    //Reads Books from txt
    bookArray = readData(bookArray);
    //Sorts which book is showable
    bookArray = sort(bookArray , sortParam);

    showBooks(bookArray);

    free(bookArray);
    return 0;
}

void clearSortParameter(struct sortingParameter *array) {
    for (int i = 0; i < 21; i++) {
        array->author[i] = 0;
        array->title[i] = 0;
        array->publisher[i] = 0;
        array->department[i] = 0;
    }
    array->year = 0;
}
