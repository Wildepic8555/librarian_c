//
// Created by wildepic on 2/1/26.
//

#include "sorting.h"
#include "data.h"

#include <stdio.h>
#include <string.h>

//Sorts which book is showable
struct bookData *sort(struct bookData *arrayToBeSorted , struct sortingParameter sortingParameter) {
    for (int i = 0 ; i < arrayLength ; i++) {
        arrayToBeSorted[i].showable = true;

        if (sortingParameter.year != arrayToBeSorted[i].year && sortingParameter.year > 0) {
            arrayToBeSorted[i].showable = false;
        }

        int len = strlen(sortingParameter.author);

        for (int j = 0 ; j < len ; j++) {
            if (arrayToBeSorted[i].author[j] != sortingParameter.author[j]) {
                arrayToBeSorted[i].showable = false;
                break;
            }
        }

        len = strlen(sortingParameter.title);

        for (int j = 0 ; j < len ; j++) {
            if (arrayToBeSorted[i].title[j] != sortingParameter.title[j]) {
                arrayToBeSorted[i].showable = false;
                break;
            }
        }

        len = strlen(sortingParameter.publisher);

        for (int j = 0 ; j < len ; j++) {
            if (arrayToBeSorted[i].publisher[j] != sortingParameter.publisher[j]) {
                arrayToBeSorted[i].showable = false;
                break;
            }
        }

        len = strlen(sortingParameter.department);

        for (int j = 0 ; j < len ; j++) {
            if (arrayToBeSorted[i].department[j] != sortingParameter.department[j]) {
                arrayToBeSorted[i].showable = false;
                break;
            }
        }
    }
    return arrayToBeSorted;
}
