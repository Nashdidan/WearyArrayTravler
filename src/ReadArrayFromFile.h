
#ifndef READARRAYFROMCSV_H
#define READARRAYFROMCSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wearyArray {
    unsigned int *str;
    int size;
    int index;
    struct wearyArray* nextArray;
};

void ReadArrayFromFile(const char* fileName, struct wearyArray** exeArray);
void FreeWearyArray(struct wearyArray* wearyArray);

#endif
