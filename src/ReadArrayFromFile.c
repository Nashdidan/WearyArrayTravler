#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "ReadArrayFromFile.h"
#define MAX_LINE (1024)

void ReadArrayFromFile(const char* fileName, struct wearyArray** exeArray){    
    int i = 0;
    char buffer[MAX_LINE];
    char* token;  
    FILE* fp; 
  
    if(exeArray == NULL){
        perror("Error: ");
        exit(-1);
    }
    if(fileName == NULL){
            perror("Error: ");
            exit(-1);
    }

    fp = fopen(fileName, "r");

        if (!fp) {
            perror("Error: ");
            exit(-1);
    }
    struct wearyArray* arrayPtr = (struct wearyArray *)malloc(sizeof(struct wearyArray));
    
    arrayPtr->size = 0;
    arrayPtr->index = 0;
    arrayPtr->nextArray = NULL;
    arrayPtr->str = NULL;
    *exeArray = arrayPtr;

    while(fgets(buffer, MAX_LINE, fp)){   
        size_t len = strcspn(buffer, "\n");
        arrayPtr->str = (unsigned int*)malloc(len * sizeof(unsigned int));  
        buffer[len] = 0;        
        token = strtok(buffer, ",");
        token = strtok(NULL, ",");
        while(token != NULL)
        {                        
            arrayPtr->str[arrayPtr->size] = (unsigned int)atoi(token);               
            token = strtok(NULL, ",");  
            arrayPtr->size++;   
        }
        i++;
        arrayPtr->index = i;            
        arrayPtr->nextArray = (struct wearyArray *)malloc(sizeof(struct wearyArray));
        arrayPtr = arrayPtr->nextArray;
    }

    fclose(fp);
}

void FreeWearyArray(struct wearyArray* wearyArray){
    struct wearyArray * runner;
    if(wearyArray == NULL){
        return;
    }
    while(wearyArray->nextArray != NULL){
        runner = wearyArray;
        wearyArray = wearyArray->nextArray;
        free(runner);
    }
}