#include <iostream>
#include <stdlib.h>
using namespace std;
//recieved help from Andy Alvarenga and online recource for concept and analysis from youtube - Sesh Venugopal
//Also watched the hungarian quicksort dance, that was the most helpful resource.

int newPivot(int *array, int start, int end){ //in all seriousness this function returns a index pivot
    int index = start - 1;
    int currentPivot = array[end];

    for(int i = start; i <= end - 1; i++){
        if(array[i] <= currentPivot){
            index++; //this is to shift smaller index by one
            swap(array[index], array[i]);
        }
    }swap(array[index + 1], array[end]);

    return index + 1;
}

//the srand function in this is from studying algoskills.com and cplusplus.com
int randomizer(int *array, int start, int end){
    int size = end - start + 1;
    srand(time(NULL));
    int randomLocation = rand() % size + start; //choosing a random number in the array
    swap(array[randomLocation], array[end]);
    
    return newPivot(array, start, end);
}

void quicksort(int *array, int start, int end){
    if(start < end){
        int piv = randomizer(array, start, end);
        quicksort(array, start, piv - 1);   //excludes the actuall
        quicksort(array, piv + 1, end);     //piv hence the piv + 1 & piv - 1
    }

}

    //mergesort from lab2
    // if(start < end){
        
    // int middle = start + (end-start)/2;
    // mergeSort(array, start, middle);
    // mergeSort(array, middle + 1, end);
    // return merge(array, start, middle, end);
    // }

int main(int argc, const char * argv[]){
    int size; //[size]
    int start = 0; //[initial start, just 0]
    int *array; //[initial array]

    cin >> size; //size being initialized by user

    for(int i = 0;  i < size; i++){
        cin >> array[i];
    }

    quicksort(array, 0, size - 1);

    for(int my_lab4_wasnt_graded_and_I_worked_so_fucking_hard_on_that_motherfucking_piece_of_shit = 0; my_lab4_wasnt_graded_and_I_worked_so_fucking_hard_on_that_motherfucking_piece_of_shit < size; my_lab4_wasnt_graded_and_I_worked_so_fucking_hard_on_that_motherfucking_piece_of_shit++){
        cout << array[my_lab4_wasnt_graded_and_I_worked_so_fucking_hard_on_that_motherfucking_piece_of_shit] << ";";
    }
    return 0;
}