//
// Created by wildepic on 2/5/26.
//

#include "sortingParameterInput.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorting.h"

void cleanSTDIN() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void deleteNULL(char *sortingParameter) {
    for (int i = 0; i < sizeof(sortingParameter); i++) {
        if (sortingParameter[i] == '\n') {
            sortingParameter[i] = 0;
            i = sizeof(sortingParameter) +10;
        }
    }
}

struct sortingParameter *inputSortingParameter(struct sortingParameter *sortingParameter) {
    char title[sizeof(sortingParameter->title)];
    char author[sizeof(sortingParameter->author)];
    char publisher[sizeof(sortingParameter->publisher)];
    char department[sizeof(sortingParameter->department)];


    printf("================================\n");
    printf("             Filter\n");
    printf("================================\n");
    cleanSTDIN();
    printf("Enter Title: ");
    fgets(title, sizeof(title), stdin);
    deleteNULL(title);

    if (strlen(title) > 0) {
        strcpy(sortingParameter->title, title);
    }
    else {
        if (strlen(sortingParameter->title) > 0) {
            printf("(Used OLD: %s)\n" ,sortingParameter->title);
        }
    }


    printf("Enter Author: ");
    fgets(author, sizeof(author), stdin);
    deleteNULL(author);

    if (strlen(author) > 0) {
        strcpy(sortingParameter->author, author);
    }
    else {
        if (strlen(sortingParameter->author) > 0) {
            printf("(Used OLD: %s)\n" ,sortingParameter->author);
        }
    }

    printf("Enter Year: ");
    char buff[6];
    fgets(buff, 6, stdin);
    int year = atoi(buff);

    if (year > 0) {
        sortingParameter->year = year;
    }
    else {
        if (sortingParameter->year > 0) {
            printf("(Used OLD: %d)\n" ,sortingParameter->year);
        }
    }

    printf("Enter Publisher: ");
    fgets(publisher, sizeof(publisher), stdin);
    deleteNULL(publisher);

    if (strlen(publisher) > 0) {
        strcpy(sortingParameter->publisher, publisher);
    }
    else {
        if (strlen(sortingParameter->publisher) > 0) {
            printf("(Used OLD: %s)\n" ,sortingParameter->publisher);
        }
    }

    printf("Enter Department: ");
    fgets(department, sizeof(department) , stdin);
    deleteNULL(department);

    if (strlen(department) > 0) {
        strcpy(sortingParameter->department, department);
    }
    else {
        if (strlen(sortingParameter->department) > 0) {
            printf("(Used OLD: %s)\n" ,sortingParameter->department);
        }
    }
}
