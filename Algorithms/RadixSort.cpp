#include <iostream>
#include <vector>
#include <cstring>
/*
Alberc Ej Salcedo
CSE100
*/

//references
//recieved help from parent who is a network engineer about counting sort and insertion sort of arrays
//recieved help from an upperclassman on radix sort and hinted that I look at the following documents/resources:
//http://www.cplusplus.com/reference/cstring/memcpy/ this is a function in c++ I read to use to copy arrays
//recieved help from this video for concept and pseudocode for counting sort
//https://www.youtube.com/watch?v=7zuGmKfUt7s

//Keynote: ended up not using counting sort because it just would not work for me. opted out using insertion sort.
//Althought this lab was very interesting, I will want to look into optimizing this on my own time
using namespace std;

//basically used my old insertion from lab01
// void insertionSort(int (*radixArray)[10], int size, int index)
void insertionSort(int **radixArray, int size, int index){
    //debug
    // cout << "Pass 4: entered insertion sort" << endl;
    int *arrayOnHeap = new int[10]; //decalred an array in heap of size 10
    int key = 0;
    int j = 0;
    for(int i = 1; i < size; i++){
            //debug
            // cout << "Pass 5: inside comparer" << endl;
        key = radixArray[i][index]; //comparer
        memcpy(arrayOnHeap, radixArray[i], sizeof(**radixArray) * 10); //insert radixArray row[i] into our arrayOnHeap
        j = i - 1; //so this j is now before i in the array

        // memcpy(arrayOnHeap, radixArray[i], sizeof(**radixArray) * 10);
        //arrayOnHeap = radixArray[i]; //we copy the row from radixArray[i] and store it into our arrayOnHeap

            //while condition from my lab01
            while(j >= 0 && radixArray[j][index] > key){ 
                    //debug
                    // cout << "Pass 6: inside while loop" << endl;
                // radixArray[j + 1] = radixArray[j];
                memcpy(radixArray[j + 1], radixArray[j], sizeof(**radixArray) * 10); 
                j = j - 1; 
            }
        // radixArray[j+1] = arrayOnHeap[j]; 
        memcpy(radixArray[j + 1], arrayOnHeap, sizeof(**radixArray) * 10);
    }delete[] arrayOnHeap; //garbage collecting in heap
}

//void radixSort(vector<int> radixArray[], int size)
void radixSort(int **radixArray, int size){
    //debug
    // cout << "Pass 2" << endl;
    for(int i = 9; i >= 0; i--){
            //debug
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
    //debug
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

    //debug
    // cout << "What about know?" << endl;
    // cout << "Pass 1" << endl;

    radixSort(radixArray, size);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            cout << radixArray[i][j] << ";";
        }cout << endl;
    }

    return 0;
}













/*   Trash   */

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


    //printing out the radixArray
    // for(int i = 0; i < size; i++){
    //     for(int j = 0; j < 10; j++){
    //         cout << radixArray[i][j] << ";";
    //     }cout << endl;
    // }
