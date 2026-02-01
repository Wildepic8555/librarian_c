#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "readBook.h"

//Read for one book the data from books.txt and gives the data into the array
void readBook(struct bookData *arrayToBeSaved  , int index , FILE *fptr) {
    char temp[5];
    char authorRead[50];
    char titleRead[50];
    char publisherRead[50];
    char yearRead[50];
    char departmentRead[50];

    //Makes the reading correct
    if (index == 0) {
        fgets(temp, 5, fptr);
    }

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
    arrayToBeSaved[index].showable = true;
}

struct bookData *readData(struct bookData *arrayToBeSaved) {
    FILE *fptr = fopen("books.txt", "r");

    // Reading the file data using fgets() in the
    // form of a block of size 30 bytes
    //Gets how many books are in books.txt
    char buff[2];
    fgets(buff, sizeof(buff), fptr);
    books = atoi(buff);

    //resizes array to correct size
    arrayLength += (books -1);
    struct bookData *array = realloc(arrayToBeSaved , sizeof(struct bookData)* arrayLength);
    arrayToBeSaved = array;

    //reads every book into the *arrayToBeSaved
    int i = 0;
    while (i < books) {
        readBook(arrayToBeSaved  , i , fptr);
        i++;
    }

    //Closes the file
    fclose(fptr);

    return arrayToBeSaved;
}