#include <iostream>
#include <vector>

//recieved help from parent who is a network engineer - Edmund Black.
//scoured the internet for resources on ratix sort concepts and code to learn
//this resolved an issue I had with mistakingly sorting columns instead or radix sort
//recieved help from this video for concept and pseudocode for counting sort
//https://www.youtube.com/watch?v=7zuGmKfUt7s
using namespace std;

vector<vector<int>> countingSort(int (*radixArray)[10], int *radix, int size, int radixSize){
    // int passArray[size][radixSize];
    vector <vector<int>> passArray;
    passArray.resize(radixSize);
    vector<int> counter(10, 0);

    for(int i = 0; i < radixSize; i++){
        counter[radix[i]]++;
        passArray[i].resize(10);
    }
    for(int i = 0; i < 9; i++){
        counter[i] = counter[i] + counter[i - 1];
    }
    for(int i = radixSize - 1; i >= 0; i--){
        // int temp = passArray[counter[radix[i]] - 1];
        // passArray[counter[radix[i]] - 1] = radixArray[i];
        // radixArray[i] = temp;
        // counter[radix[i]] = counter[radix[i]] - 1;
        swap(passArray[counter[radix[i]] - 1], radixArray[i]);
        counter[radix[i]] = counter[radix[i]] - 1;
    }
    return passArray;
}


void radixSort(int (*radixArray)[10], int size){
    // vector<int> radix;
    vector<int> sortedRadix;
    for(int i = 9; i >= 0; i--){
    vector<int> radix;
        for(int j = 0; j < size; j++){
            radix.push_back(radixArray[j][i]); 
        }
        int radixSize = radix.size();
        radixArray = countingSort(radixArray, radix, size, radixSize);

    }

}


int main(){
    int size, input;
    int count = 0;
    cin >> size;
    vector<int> array;

    //make a 2D array for input
    int radixArray[size][10];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            if(count != 10){
                cin >> input;
                radixArray[i][j] = input;
            }
        }
    }

    radixSort(radixArray, size);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            cout << radixArray[i][j] << ";";
        }cout << endl;
    }

    //printing out the radixArray
    // for(int i = 0; i < size; i++){
    //     for(int j = 0; j < 10; j++){
    //         cout << radixArray[i][j] << ";";
    //     }cout << endl;
    // }
    return 0;
}













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
    