#include <iostream>
#include <vector> 

using namespace std;

int* merge(int *array, int start, int middle, int end){
    // int size = sizeof(left) + sizeof(right);
    int size = end;
    int *temp = new int[size];
cout << "Pass7!" << endl;
    //crawlers
    int left = start, right = middle + 1;
    int k = 0;
cout << "Pass8!" << endl;
    while(left <= middle && right <= end){
        if(array[left] < array[right]){
            temp[k] = array[left];
            left++;
            k++;
            cout << "Pas9A!" << endl;
        }
        else{
            temp[k] = array[right];
            right++;
            k++;
            cout << "Pass9B!" << endl;
        }
        while(left <= middle){
            temp[k] = array[left];
            left++;
            k++;
            cout << "Pass10A!" << endl;
        }                           //Both of these while loops are written with a help from my senior friends. My code kept breaking without these two while loops.
        while(right <= end){        //I understand that these are in placed since all arrays are not even
            temp[k] = array[right];     //these are for when their are an extra element in either side of the split
            right++;
            k++;
            cout << "Pass10B!" << endl;
        }
        cout << "Pass11!" << endl;
    } 
    for(int i = start; i < end + 1; i++){
        array[i] = temp[i];
        cout << array[i] << ";" << endl;
    }
    return array;
}

void mergeSort(int *array, int start, int end){
    int size = start + (end - 1);
    cout << "----------whats the array-----------" << endl;
    for(int i = start; i < end; i++){
    cout << array[i] << ";" << endl;
    }
    cout << "----------whats the array-----------" << endl;
    if(start < end){
        int middle =(size/2);
        cout << "This is the value of middle:" << middle << endl;
    mergeSort(array, start, middle);
    mergeSort(array, middle + 1, end);
    // cout << "-------------------------------" << endl;
    // for(int i = start; i < end; i++){
    //     cout << array[i] << ";";
    
    // cout << "-------------------------------" << endl;
    // return merge(array, start, middle, end);
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

    for(int i = 0; i < size; i++){
        cout << arr[i] << ";";
    }
cout << "Pass1!" << endl;

mergeSort(arr, (size - size), size - 1);
    // int *newArr = mergeSort(arr, (size - size), size);
// cout << "PassEnd!" << endl;
//     for(int i = 0; i < size; i++){
//         cout << newArr[i] << ";";
//     }

    return 0;
}