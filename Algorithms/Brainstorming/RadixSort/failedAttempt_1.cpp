#include <iostream>
#include <algorithm>

using namespace std;

// void sortColumn(int *array, int size/* int (*radixArray)[10], int size2*/){
//     sort(array, array+size);
// }

int input(istream& in=cin){
    int input;
    in >> input;
    return input;
}

int main(){
    int size;
    int count = 0;
    cin >> size;

    int radixArray[size][10];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            if(count != 10){
                radixArray[i][j] = input();
            }
        }
    }

    int arrayC[size]; //array column
    //push columns to arrayC to be sorted in sortColumn
    for(int j = 0; j < 10; j++){
        for(int i = 0; i < size; i++){
            arrayC[i] = radixArray[i][j];
            // cout << "pass" << i << endl;
        }
        // cout << "PASSED" << endl;
        // sortColumn(arrayC, size/*, radixArray, j*/);
        count_sort(arrayC, arrayC+size);
            for(int row = 0; row < size; row++){
                radixArray[row][j] = arrayC[row];
            }
    }

    //printing out the radixArray
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            cout << radixArray[i][j] << ";";
        }cout << endl;
    }
    return 0;