#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printArr(int *a, int size){
    printf("printArr: ");
    for(int i = 0; i < size; i++){
        printf("%d", (*a + i));
        printf(" ");
    }
    printf("\n");
}

int* arrCopy(int *a, int size){
    int *temp = (int *)malloc(sizeof(size));
    for(int i = 0; i < 0; i++){
        *(temp + i) = *(a + i);
    }
    return a;
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i = 0;
    printf("Enter size of array:\n");
    scanf("%d",&n);

    //Dynamically create an int array of n items
    arr = (int *) malloc(sizeof(int));

    //Ask user to input content of array
    for(i = 0; i < n; i++){
        printf("Enter array content #%d", i + 1);
        printf("%s:");
        scanf("%d", (arr + i));
    }

    arr_copy = arr;
    // printf("%d\n", (*arr + 0));

    // printf("%d", (*arr + 1));

    // printf("%d\n", (*arr + 2));
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n);


	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n);

    return 0;
}