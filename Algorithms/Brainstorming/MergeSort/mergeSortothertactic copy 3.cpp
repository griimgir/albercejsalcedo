#include <iostream>
#include <vector> 

using namespace std;

int* merge(int *array, int start, int middle, int end){
    // cout << "---------------> " << start << endl;
    // int size = sizeof(left) + sizeof(right);
    // int size = end;
    // int *temp = new int[size];  this was my old temp array
    
    //sizes for left an right temp arr[]
    int sizeL = (middle - start + 1);
    int sizeR = (end - middle);

    //temp arrays and initializers
    // int *left = new int[sizeL];
    // int *right = new int[sizeR];
    int left[sizeL];
    int right[sizeR];

//these for loops, i got helped from my friend Hoa Nyuen
    int i, j;
    for(i = 0; i < sizeL; i++){
        left[i] = array[start + i]; //this 
    }                               //and
    for(j = 0; j <sizeR; j++){
        right[j] = array[middle + 1+ j]; //this was what he helped me with. These conditions specifically.
    }
//now we have a left array and a right array that needs to be merged back together.

    //crawlers
    int lefty = 0, righty = 0;
    int k = start;

    while(lefty < sizeL && righty < sizeR){
        //copying the left array into the main array if condtion is met
        if(left[lefty] < right[righty]){
            array[k] = left[lefty];
            lefty++;
            k++;
        }
        //else the right side will be copied to the main array if contion of if is not met
        else{
            array[k] = right[righty];
            righty++;
            k++;
        }
    }

        while(lefty < sizeL){
            array[k] = left[lefty];
            lefty++;
            k++;
        }                           
        while(righty < sizeR){        //I understand that these are in placed since all arrays are not even
            array[k] = right[righty];     //these are for when their are an extra element in either side of the split
            righty++;
            k++;
        } 
    // for(int i = start; i < end + 1; i++){
    //     array[i] = temp[i];
    //     cout << array[i] << ";" << endl;
    //}
    return array;
}

int* mergeSort(int *array, int start, int end){
    // cout << "----------whats the array-----------" << endl;
    // for(int i = start; i < end; i++){
    // cout << array[i] << ";" << endl;
    // }
    // cout << "----------whats the array-----------" << endl;
    if(start < end){
        // int middle = (start + end)/2;
        int middle = start + (end-start)/2;
        // cout << endl;
        // cout << "middle: " << middle << "start: " << start << "end: " << end << endl;
    mergeSort(array, start, middle);
    mergeSort(array, middle + 1, end);
    // cout << "-------------------------------" << endl;
    // for(int i = start; i < end; i++){
    //     cout << array[i] << ";";
    
    // cout << "-------------------------------" << endl;
    return merge(array, start, middle, end);
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

    // for(int i = 0; i < size; i++){
    //     cout << arr[i] << ";";
    // }
// cout << "Pass1!" << endl;

// mergeSort(arr, (size - size), size - 1);
    int *plsFuckingWorkitsLiterallyBeen3fuckingDays = mergeSort(arr, 0, size - 1);
// cout << "PassEnd!" << endl;
    for(int i = 0; i < 6; i++){
        cout << plsFuckingWorkitsLiterallyBeen3fuckingDays[i] << ";";
    }

    return 0;
}