#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "readBook.h"
#include "showBooks.h"
#include "sorting.h"
#include "sortingParameterInput.h"


void clearSortParameter(struct sortingParameter *array);
void header();

int main(void) {
    //init the bookarray and also reads the values into it
    struct bookData *bookArray = malloc(arrayLength *sizeof(struct bookData));
    struct sortingParameter sortParam;
    char userInput = 'a';

    //Clear residue were now the sorting parameters are
    clearSortParameter(&sortParam);

    //Reads Books from txt
    bookArray = readData(bookArray);

    while (userInput != 'q') {
        //Sorts which book is showable
        bookArray = sort(bookArray , sortParam);
        header();
        showBooks(bookArray);
        userInput = getchar();
        system("clear");

        if (userInput == 'e') {
            inputSortingParameter(&sortParam);
            system("clear");
        }
        else if (userInput == 'r') {
            char empty[21] = {0};

            strcpy(sortParam.title, empty);
            strcpy(sortParam.publisher, empty);
            strcpy(sortParam.department, empty);
            strcpy(sortParam.author, empty);
            sortParam.year = 0;
        }
    }


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

void header() {
    printf("================================\n");
    printf("           Librarian\n");
    printf("================================\n");
    printf("         ==Commands==\n");
    printf("         E to filter\n");
    printf("         R to reset filter\n");
    printf("         Q to quit\n");
    printf("================================\n");
}
