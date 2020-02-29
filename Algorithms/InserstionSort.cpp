#include <iostream>

using namespace std;

int main(int argc, const char * argv[]){
    int input;
    int size;

    //enter inputs
    // cout << "Input" << endl;
    // cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }    
    // cout << " " << endl;

    //the key is holding the current number, j is a shifter to move around the array, 
    //and i is where we currently are in the array
    int key = 0;
    int j = 0;
    // cout << "Output" << endl;
    for(int i = 1; i < size; i++){
        key = arr[i];
        j = i - 1; //so this j is now before i in the array
            while(j >= 0 && arr[j] > key){ //this condition is crucial, it allows j to be before i and making sure key is less then the previous array position
                arr[j + 1] = arr[j]; //this replaces the current postion with the previous position's stored value
                j = j - 1; //set j position back by one to increment outside of while loop
            }
        arr[j+1] = key; //that key we storeed is now in the correct position
        
        //now printing it out as it sorts it
        for(int k = 0; k < i + 1; k++){
            cout << arr[k] << ";";
        }
        cout << "" << endl;
    }
    //this was to test if my sorting was correct
    // for(int i = 0; i < size; i++){
    //     cout << arr[i] << ";";
    // }
    return 0;
}