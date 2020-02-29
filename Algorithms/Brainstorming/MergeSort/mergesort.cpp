#include <iostream>
#include <vector> 

using namespace std;

// void merge(int *array, int start, int middle, int end){
//     //temporary array
//     // vector<int> temp;
//     int temp[size];
//     //crawlers
//     int right = start, left = (middle);

//     while(right <= start && left <= end){
//         if(array[right] <= array[left]){
//             temp.push_back(array[right]);
//             right++;
//         }
//         else{
//             temp.push_back(array[left]);
//             left++;   
//         }

//         for(int i = 0; i < end; i++){
//             array[i] = temp.at(i);
//         }

//     }
// }

// void merge(int array[], int start, int middle, int end){
//     //crawlers
//     int right = start, left = middle, t = 0;
//     //temporary array
//     int temp[end];

//     while(right <= middle && left <= end){
//         if(array[right] <= array[left]){
//             temp[t] = array[right];
//             t++;
//             right++;
//         }
//         else{
//             temp[t] <= array[left];
//             t++;
//             left++;
//         }
//         for(int i = 0; i < end; i++){
//              array[i] = temp[i];
//          }
//     }
//     for(int i = 0; i < end; i++){
//         cout << array[i] << ";";
//     }
// }

int* merge(int *left, int *right, int size){
    int *temp = new int[size];

    //crawlers
    int lefty = 0, righty = 0;
    int k = 0;

    while(k <= size){
        if(left[lefty] < right[righty]){
            temp[k] = left[lefty];
            lefty++;
            k++;
        }
        else{
            temp[k] = right[righty];
            righty++;
            k++;
        }
    } 
    return temp;
}

int* mergeSort(int *array, int start, int end){
    int size = end + start;
    // if(size <= 0){
    //     return array;
    // }
    if(start < end){
        int middle = size / 2;
    // int *left = new int[array[0, (size/2)]];
    // int *right = new int[array[((size/2) + 1), size]];
    
    int *left =  mergeSort(array, start, middle);
    int *right = mergeSort(array, middle + 1, end);

    //inserting first half of array to left[]
    // for(int i = 0; i < sizeof(left); i++){
    //     left[i] = array[i];
    // }
    // for(int i = ((size/2) + 1); i < sizeof(right); i++){
    //     right[i] = array[i];
    // }
    // for(int i = 0; i < sizeof(left); i++){
    //     cout << left[i] << ";L";
    // }
    // for(int i = 0; i < sizeof(right); i++){
    //     cout << right[i] << "iR";
    // }

    return merge(left, right, size);
    
    }
}


// void mergesort(int*array, int begin, int end, int size){
//     //recursive function with first and last indecies of array
//     int mid;
//         mid = (begin + end)/2;
//         mergesort(array, begin, mid, size);
//         mergesort(array, mid+1, end, size);
//         merge(array, begin, end, mid, size);
// }

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

    //positions
    // int *start;
    // int *middle;
    // int *end;
    // start = arr;
    // middle = &arr[size/2];
    // end = &arr[size];

    // int start = 0;
    // int end = size;
    // int *array;
    // array = arr;
    // int start = size - (size - 1);
    // int *array = arr;

    for(int i = 0; i < size; i++){
        cout << arr[i] << ";";
    }

    int *newArr = mergeSort(arr, 0, size);

    for(int i = 0; i < size; i++){
        cout << newArr[i] << ";";
    }
    //merge(arr, start, middle, end, size);

    return 0;
}