#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "readBook.h"
#include "sorting.h"

int main(void) {
    //init the bookarray and also reads the values into it
    struct bookData *bookArray = malloc(arrayLength *sizeof(struct bookData));
    struct sortingParameter sortParam;

    //Test
    sortParam.author[0] = 'w';
    sortParam.author[1] = 'i';
    sortParam.title[0] = 'c';
    sortParam.title[1] = 'e';
    sortParam.publisher[0] = 'w';
    sortParam.publisher[1] = 'i';
    sortParam.year = 2022;
    sortParam.department[0] = 'a';
    sortParam.department[1] = 'l';

    //Reads Books from txt
    bookArray = readData(bookArray);
    //Sorts which book is showable
    bookArray = sort(bookArray , sortParam);

    //Test
    if (bookArray[0].showable == true) {
        printf("%s" , bookArray[0].title);
    }
    if (bookArray[1].showable == true) {
        printf("%s" , bookArray[1].title);
    }
    if (bookArray[2].showable == true) {
        printf("%s" , bookArray[2].title);
    }

    free(bookArray);
    return 0;
}
