#include <iostream>

using namespace std;

//Andy Alverenga has helped me in this lab with one small thing. He
//told me to pass on the size each time instead of declaring a new sign
//it's not a good idea to overwrite the size each time.

//int* Max_Heap(int *array, int c)
void Max_Heap(int *array, int size, int c){
    // int size = sizeof(array)/sizeof(array[0]);
    int largest = c;
    int left = (2 * c); //2c + 1
    int right = (2 * c) + 1;    //2c + 2

    // int max = array[c]; //c indicates the current position for max
    if(left < size && array[left] > array[largest]){
        largest = left;
    }
    // else{
    //     largest = c;
    //}
    if(right < size && array[right] > array[largest]){
        largest = right;
    }
    if(largest != c){
        swap(array[c], array[largest]);
        Max_Heap(array, size, largest);
    }
        // int size = sizeof(array)/sizeof(array[0]);
    // for(int i = 0; i < size; i++){
    //     cout << array[i] << ";";
    // }
// return array;

}

//int* BuildMaxHeap(int *array){
void BuildMaxHeap(int *array, int size){
    // int size = sizeof(array)/sizeof(array[0]);
    for(int i = size - 1; i >= 0; i--){
        Max_Heap(array, size, i);
    }
    // return array;
}

void HeapSort(int *array, int size){
    // int *built_heap = BuildMaxHeap(array, size);
    BuildMaxHeap(array, size);

    // for(int i = (sizeof(built_heap)/sizeof(built_heap[0])) - 1; i >= 0; i--){
    for(int i = size - 1; i >= 0; i--){
        swap(array[0], array[i]);

        // int newSize = (sizeof(array)/sizeof(array[0])) - 1;
        Max_Heap(array, i, 0);
    }
    // return array;
}

int main(int argc, const char * argv[]){
    int *array;
    int size;

    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }

    HeapSort(array, size); //completeley useless, i just like to 
                                         //print out in main, it's very satisfying when your code comes to a full circle.

    for(int i = 0; i < size; i++){
        cout << array[i] << ";";
    }

    return 0;
}