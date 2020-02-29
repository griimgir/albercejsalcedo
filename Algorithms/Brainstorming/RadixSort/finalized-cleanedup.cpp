#include <iostream>
#include <vector>
#include <cstring>
/*
Alberc Ej Salcedo
CSE100
*/
using namespace std;

//basically used my old insertion from lab01
void insertionSort(int **radixArray, int size, int index){
        //debug
        //cout << "Pass 4: entered insertion sort" << endl;
    int *arrayOnHeap = new int[10]; //decalred an array in heap of size 10
    int key = 0;
    int j = 0;
    for(int i = 1; i < size; i++){
        //debug
        //cout << "Pass 5: inside comparer" << endl;
        key = radixArray[i][index]; //comparer
        memcpy(arrayOnHeap, radixArray[i], sizeof(**radixArray) * 10); //insert radixArray row[i] into our arrayOnHeap
        j = i - 1; //so this j is now before i in the array
            //while condition from my lab01
            while(j >= 0 && radixArray[j][index] > key){ 
                //debuggerooni
                //cout << "Pass 6: inside while loop" << endl;
                memcpy(radixArray[j + 1], radixArray[j], sizeof(**radixArray) * 10); // radixArray[j + 1] = radixArray[j];
                j = j - 1; 
            } 
        memcpy(radixArray[j + 1], arrayOnHeap, sizeof(**radixArray) * 10);         // radixArray[j+1] = arrayOnHeap[j];
    }delete[] arrayOnHeap; //garbage collecting in heap
}

void radixSort(int **radixArray, int size){
    //debooger
    // cout << "Pass 2" << endl;
    for(int i = 9; i >= 0; i--){
            //debugOFF
            // cout << "Pass 3: inside radixSort for()loop" << endl;
        insertionSort(radixArray, size, i);
    }
}

int main(){
    int size, input;
    int count = 0;
    cin >> size;
    // vector<int> array;

    //make a 2D array for input
    int inputArray[size][10];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            if(count != 10){
                cin >> input;
                inputArray[i][j] = input;
            }
        }
    }
    //deburger
    // cout << "Did it even make it here?" << endl;
    int *radixArray[size];
    for(int i = 0; i < size; i++){
        radixArray[i] = new int[10];    //making a 2D array that is passable through functions
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            radixArray[i][j] = inputArray[i][j];
        }
    }
    //deBegForMyLife
    // cout << "Pass 1" << endl;

    radixSort(radixArray, size);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            cout << radixArray[i][j] << ";";
        }cout << endl;
    }
    return 0;
}















/*  Trash pile  */

    //printing out the radixArray
    // for(int i = 0; i < size; i++){
    //     for(int j = 0; j < 10; j++){
    //         cout << radixArray[i][j] << ";";
    //     }cout << endl;
    // }

// int input(istream& in=cin){
//     int input;
//     in >> input;
//     return input;
// }


    // for(int i = 0; i < size; i++){
    //     cin >> input;
    //     array.push_back(input);
    // }



    // vector<vector<int>> radixArray;
    // for(int i = 0; i < size; i++){
    //     for(int j = 0; j < 10; j++){
    //         if(count != 10){
    //             cin >> input;
    //             radixArray.push_back(input);
    //         }
    //     }
    // }
    

    // void countingSort(vector<int> radixArray, int size, int index){
//     vector <vector<int>> tempArray;
//     tempArray.resize(size);
//     //preparing a temparray
//     for(int i = 0; i < size; i++){
//         tempArray[i].resize(10);    //making a temp 2D array
//     }



// }
