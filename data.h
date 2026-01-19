//
// Created by wildepic on 1/16/26.
//

#ifndef LIBRARIAN_DATA_H
#define LIBRARIAN_DATA_H

struct bookData {
  char author[50];
  char title[50];
  char publisher[50];
  int year;
  char department[25];
};

int arrayLength = 1;
int books = 0;

#endif //LIBRARIAN_DATA_H