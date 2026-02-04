//
// Created by wildepic on 1/16/26.
//

#ifndef LIBRARIAN_DATA_H
#define LIBRARIAN_DATA_H

struct bookData {
  char author[21];
  char title[21];
  char publisher[21];
  int year;
  char department[21];
  bool showable;
};

extern int arrayLength;
extern int books;

#endif //LIBRARIAN_DATA_H