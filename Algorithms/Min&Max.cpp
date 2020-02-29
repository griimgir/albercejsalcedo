#include <iostream>
#include <vector> 
#include <string>

using namespace std;

int main(int argc, const char * argv[]){
    string input;
    int size;

    //enter inputs
    // cout << "Input" << endl;
    // cout << "Enter array size: ";
    cin >> size;

    int ins[size];
    for(int i = 0; i < size; i++){
        cin >> ins[i];
    }    
    // cout << " " << endl;

    //finding max
    int max = ins[0];
    int min = ins[0];
    for(int i = 1; i < size; i++){
        if(ins[i] > max){
            max = ins[i];
        }
        if(ins[i] < min){
            min = ins[i];
        }
    }
    // cout << "Output" << endl;
    cout << max << ";" << min;

    return 0;
}