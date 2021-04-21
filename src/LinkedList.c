#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE (1024)

struct wearyArray {
    unsigned int *str;
    size_t size;
    size_t index;
    struct wearyArray* nextArray;
};


void ReadArrayFromCsv(const char* fileName, struct wearyArray** exeArray){    
    FILE* fp = fopen(fileName, "r"); 
    int i = 0;
    char buffer[MAX_LINE];
    char* token;
    if(exeArray == NULL){
        printf("**invalid array**");
        exit(-1);
    }
    
    struct wearyArray* arrayPtr = (struct wearyArray *)malloc(sizeof(struct wearyArray));
    
    arrayPtr->size = 0;
    arrayPtr->index = 0;
    arrayPtr->nextArray = (*exeArray);
    arrayPtr->str = (*exeArray)->str;
    *exeArray = arrayPtr;

    if (!fp) {
        printf("Can't open file\n"); 
        exit(-1);
    }
    while(fgets(buffer, MAX_LINE, fp)){        
        arrayPtr->str = (unsigned int*)malloc(strcspn(buffer, "\n") * sizeof(unsigned int));  
        buffer[strcspn(buffer, "\n")] = 0;        
        token = strtok(buffer, ",");
        token = strtok(NULL, ",");
        while(token != NULL)
        {                        
            *(arrayPtr->str + arrayPtr->size) = atoi(token);               
            token = strtok(NULL, ",");  
            arrayPtr->size++;   
        }
        i++;
        arrayPtr->index = i;            
        arrayPtr->nextArray = (struct wearyArray *)malloc(sizeof(struct wearyArray));
        arrayPtr = arrayPtr->nextArray;
    }
    arrayPtr->nextArray = NULL;

    fclose(fp);
}

void FreeWearyArray(struct wearyArray *wearyArray){
    struct wearyArray * runner;
    if(wearyArray == NULL){
        return;
    }
    while(runner != NULL){
        runner = wearyArray;
        wearyArray = wearyArray->nextArray;
        free(runner);
    }
}

// int main(){
//     size_t i = 0;
//     struct wearyArray* exeArray;
//     ReadArrayFromCsv("WearyArray.csv", &exeArray);
//     i = exeArray->size;
//     printf("index: %lu", exeArray->index);
//     for(i = 0; i < exeArray->nextArray->size ; i++){
//         printf("num: %u", *exeArray->nextArray->str);
//         (exeArray->nextArray->str) ++;
//     }
//     FreeWearyArray(exeArray);
//     return 0;
// }
