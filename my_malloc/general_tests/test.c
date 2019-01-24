#include <stdlib.h>
#include <stdio.h>
#include "my_malloc.h"

int* initArray(int size, char method){
    int* array = method=='f' ? ff_malloc(size * sizeof(*array)) : bf_malloc(size * sizeof(*array));
    if(array){
        for(int i=0; i<size; i++){
            array[i] = i;
        }
    }
    return array;
}

int main(int argc, char *argv[]){
  if(argc != 3){
    printf("argc error\n");
    return 1;
  }
  int size = atoi(argv[1]);
    char method = argv[2][0];
    printf("size: %d\n", size);
    printf("method: %c\n", method);

    int* array = initArray(size, method);
    for(int i=0; i<size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}