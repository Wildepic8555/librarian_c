//
// Created by wildepic on 2/4/26.
//

#include "showBooks.h"
#include <stdio.h>
#include "data.h"

struct bookData *showBooks(struct bookData *arrayToBePrinted) {
    for (int i = 0; i < books; i++) {
        if (arrayToBePrinted[i].showable == true) {
            printf("Title:      %21s" , arrayToBePrinted[i].title);
            printf("Autor:      %21s" , arrayToBePrinted[i].author);
            printf("Publisher:  %21s" , arrayToBePrinted[i].publisher);
            printf("Department: %21s" , arrayToBePrinted[i].department);
            printf("Year:                       %d\n" , arrayToBePrinted[i].year);
            printf("================================\n");
        }
    }
}