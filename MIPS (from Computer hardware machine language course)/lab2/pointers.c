#include <stdio.h>

int main(){
    int x, y, *px, *py;
    int arr[10];

    x = 0; 
    y = 0;
    
    px = &x;
    py = &y;
    
    // printf("%a", *px);
    // printf("%d\n",px);

    for(int i = 0; i < 10; i++){
        arr[i] = i + 1;
        // printf("%d\n", arr[i]);
    }
    printf("Address of x: ");
    printf("%p\n", &x);
    printf("Address of y: ");
    printf("%p\n", &y);

    for(int i = 0; i < 10; i++){
        printf("Address of array ");
        printf("%d", i);
        printf(": ");
        printf("%p\n", &arr[i]);
    }

    px = arr;
    // *px++;
    // *px++;
    // printf("%d\n", *px);
    // px++;
    // printf("%d\n", *px);

    for(int i = 0; i < 10; i++){
        printf("Array %d", i);
        printf(" contains: %d\n", *px);
        px++;
    }

return 0;
}