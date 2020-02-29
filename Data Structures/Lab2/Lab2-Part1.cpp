#include <iostream>

using namespace std;

//Write a C++ program that prompts the user to enter an int value. Your program should then display the
//byte array representation in little-endian format.

int main(){

int n = 0;

cout << "Enter an integer value to store: ";
cin >> n;

int* p = &n;
unsigned char* a = (unsigned char*)p;   

cout << hex << "This i the byte array in little-endian format" << endl;
cout << hex << "Value at byte 1: " << (long) *a << endl;        
cout << hex << "Value at byte 2: " << (long) *(a + 1) << endl;  
cout << hex << "Value at byte 3: " << (long) *(a + 2) << endl;  
cout << hex << "Value at byte 4: " << (long) *(a + 3) << endl;  
cout << "" << endl;

cout << "Little-endian format: " << (long) *a << " " << (long) *(a + 1) << " " << (long) *(a + 2) << " " << (long) *(a + 3) << endl;

    return 0;
}