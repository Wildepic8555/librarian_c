#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "readBook.h"

int main(void) {
    struct bookData *bookArray = malloc(arrayLength *sizeof(struct bookData));
    bookArray = readData(bookArray);

    printf("%s", bookArray[1].author);

    free(bookArray);
    return 0;
}