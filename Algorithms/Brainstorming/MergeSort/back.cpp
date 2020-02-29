#include <iostream>
#include <vector> 

using namespace std;

void merge(int *array, int start, int middle, int end){
    // int size = sizeof(left) + sizeof(right);
    int size = (start + end) + 1;
    int *temp = new int[size];

    //crawlers
    int left = start, right = middle + 1;
    int k = 0;

    while(k <= size){
        if(array[left] < array[right]){
            temp[k] = array[left];
            left++;
            k++;
        }
        else{
            temp[k] = array[right];
            right++;
            k++;
        }
        while(left < middle + 1){
            temp[k] = array[left];
        }                           //Both of these while loops are written with a help from my senior friends. My code kept breaking without these two while loops.
        while(right < end + 1){        //I understand that these are in placed since all arrays are not even
            temp[k] = array[right];     //these are for when their are an extra element in either side of the split
        }
        for(int i = 0; i < sizeof(array); i++){
            array[i] = temp[i];
        }
    } 
    for(int i = 0; i < sizeof(array); i++){
        cout << array[i] << ";";
    }
}

void mergeSort(int *array, int start, int end){
    int size = sizeof(array);

    if(start < end){
        int middle = size / 2;
cout << "Pass3!" << endl;
    mergeSort(array, start, middle);
    mergeSort(array, middle + 1, end);
    merge(array, start, middle, end);
cout << "Pass4!" << endl;
    }
}

int main(){
    //size of the array
    int size = 0;
    cin >> size;

    //create the array and initialize each elemrnt with user input
    int arr[size];
    // vector<int> *arr = new vector<int> (size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
cout << "Pass1!" << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << ";";
    }
cout << "Pass2!" << endl;
    mergeSort(arr, 0, size - 1);

    return 0;
}