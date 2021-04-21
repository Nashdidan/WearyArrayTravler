#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <errno.h>
#include "ReadArrayFromFile.h"
#include "Stack.h"

#define MAX_FILE_NAME (1024)

unsigned int lastLocation = 0;

void FreeStack(struct Stack* visitedArray){
    free(visitedArray->array);
    free(visitedArray);
}

int CountAddress(int *i, const unsigned int* array, const int size, struct Stack **visitAddresses, bool* dirtyAddress)
{
    lastLocation = *i;
    *i += array[*i - 1];
    if(*i == size) return 1;
    if(array[*i - 1] > size - 1 || array[*i - 1] < 0 || *i == lastLocation){        
        if(isEmpty(*visitAddresses) == 1) return 0;
        *i = pop(*visitAddresses);        
        if(*i == 0) return 0;
        if((int)(*i - array[*i - 1]) < 0) return 2;
        *i -= array[*i - 1];
    } else if(!dirtyAddress[*i]) {
        push(*visitAddresses, *i);
    }
    return 0;
}

bool IsArrayWeary(const unsigned int* array, const int size) {
    int i = 1;
    int flag = 0;
    bool dirtyAddress[size];
    if(size == 0 || *array == size - 1){
        return true;
    }
    else if(*array == 0 || *array > size - 1){
        return false;
    }

    struct Stack* visitAddresses = createStack(size);
    memset(dirtyAddress, 0, size*sizeof(bool));
    push(visitAddresses, i);
    
    dirtyAddress[i] = true;
    
    while(isEmpty(visitAddresses) == 0){
        dirtyAddress[i] = true;
        flag = CountAddress(&i, array, size, &visitAddresses, dirtyAddress);   
        if(flag == 1) {
            FreeStack(visitAddresses);    
            return true;
        }
        if(flag == 2) break;     
    }   
    FreeStack(visitAddresses);

    return false;    
}

void PrintWearyArrayResult(bool result, int arrayNumber) {
    if(result == true) printf("array no.%d is Weary!\n", arrayNumber);
    else{
        printf("array no.%d isn't Weary...\n", arrayNumber);
    }
}

int main() 
{ 
    int i = 0;
    bool isIt = false;
    char fileDest[MAX_FILE_NAME] = {"\n"};
    struct wearyArray* exeArray = NULL;
    struct wearyArray* arrayPtr = NULL;

    printf("enter your file destenation: ");
    fgets(fileDest, MAX_FILE_NAME, stdin);
    if (strlen(fileDest) == 0) {
        perror("Error: ");
        return 0;
    }
    fileDest[strlen(fileDest) - 1] = 0;
    ReadArrayFromFile(fileDest, &exeArray);

    arrayPtr = (struct wearyArray*)malloc(sizeof(*arrayPtr));

    arrayPtr->index = exeArray->index;
    arrayPtr->nextArray = exeArray->nextArray;
    arrayPtr->size = exeArray->size;
    arrayPtr->str = exeArray->str;

    while(arrayPtr != NULL){
        if(arrayPtr->str != NULL){
            isIt = IsArrayWeary(arrayPtr->str, arrayPtr->size);
            PrintWearyArrayResult(isIt, ++i);
        }
        arrayPtr = arrayPtr->nextArray;        
    }
    FreeWearyArray(exeArray);
    free(arrayPtr);
    return 0;    
}



// int recursive(int pos, const int *arr, bool *visited, int len) {
//     if (pos > len || pos < 0 || visited[pos] == true) {
//         return false;
//     } else if (pos == len) {
//         return true;
//     }
//     visited[pos] = true;
//     if (recursive(pos + arr[pos], arr, visited, len) == true) {
//         return true;
//     }
//     return recursive(pos - arr[pos], arr, visited, len);    
// }