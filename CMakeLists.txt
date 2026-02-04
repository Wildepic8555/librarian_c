cmake_minimum_required(VERSION 4.1)
project(librarian C)

set(CMAKE_C_STANDARD 23)

add_executable(librarian main.c
        data.h
        readBook.c
        readBook.h
        data.c
        sorting.c
        sorting.h
        showBooks.c
        showBooks.h
)
