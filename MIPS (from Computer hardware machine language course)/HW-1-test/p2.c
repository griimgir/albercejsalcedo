#include <stdio.h>

int main(){
    int *array1;
    int *array2;
    int size = 10;

    for(int i = 0; i < size; i++){
        array1[i] = 1;
    }
    for(int j = 0; j < size; j++){
        array2[j] = 1;
    }

    for(int i = 0; i < size; i++){
        printf("Array 1%d\n", array1[i]);
    }

    for(int i = 0; i < size; i++){
        printf("Array 2%d\n", array2[i]);
    }

    return 0;
}