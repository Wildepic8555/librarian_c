#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

void readData(struct bookData *arrayToBeSaved);
void changeArraySize(struct bookData *arrayToChanged , int sizeToChange , int operation);


int main(void) {
    struct bookData *bookArray = malloc(arrayLength *sizeof(struct bookData));
    readData(bookArray);
    free(bookArray);
    return 0;
}

void readBook(struct bookData *arrayToBeSaved  , int index , FILE *fptr) {
    char trash[5];
    char authorRead[50];
    char titleRead[50];
    char publisherRead[50];
    char yearRead[50];
    char departmentRead[50];


    fgets(trash, sizeof(trash), fptr);
    fgets(authorRead, 50, fptr);
    fgets(titleRead, 50, fptr);
    fgets(publisherRead, 50, fptr);
    fgets(yearRead, 50, fptr);
    fgets(departmentRead, 50, fptr);

    int yearReadInt = atoi(yearRead);

    strcpy(arrayToBeSaved[index].author, authorRead);
    strcpy(arrayToBeSaved[index].title, titleRead);
    strcpy(arrayToBeSaved[index].publisher, publisherRead);
    arrayToBeSaved[index].year = yearReadInt;
    strcpy(arrayToBeSaved[index].department, departmentRead);
}

void readData(struct bookData *arrayToBeSaved) {
    FILE *fptr = fopen("books.txt", "r");

    // Reading the file data using fgets() in the
    // form of a block of size 30 bytes
    char buff[2];
    fgets(buff, sizeof(buff), fptr);
    books = atoi(buff);


    arrayLength += (books -1);
    struct bookData *array = realloc(arrayToBeSaved , sizeof(struct bookData)* arrayLength);
    arrayToBeSaved = array;

    int i = 0;
    while (i < 2) {
        readBook(arrayToBeSaved  , i , fptr);
        i++;
    }


    printf("%d" , arrayToBeSaved[1].year);
    fclose(fptr);
};