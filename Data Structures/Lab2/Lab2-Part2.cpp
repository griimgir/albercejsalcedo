#include <iostream>

using namespace std;

// pos  0   1   5   9   17
// size 1   4   4   8   1

int main(int argc, const char * argv[]) {
    int sizes[5] = {1, 4, 4, 8, 1};     //bytes

    void* stash = malloc(18);           
    
    unsigned char* c = (unsigned char*)stash;

    *c = 88;
    c++;
    
    *c = 192;
    c++;
    
    *c = 7;
    c++;
    
    *c = 0;
    c++;
    
    *c = 0;
    c++;
    
    *c = 21;
    c++;
    
    *c = 205;
    c++;
    
    *c = 91;
    c++;
    
    *c = 7;
    c++;

    *c = 162;
    c++;
    
    *c = 48;
    c++;
    
    *c = 210;
    c++;
    
    *c = 178;
    c++;
    
    *c = 244;
    c++;
    
    *c = 16;
    c++;
    
    *c = 34;
    c++;
    
    *c = 17;
    c++;
    
    *c = 80;
    
    cout << "The stash contents are: " << endl;
    

    // Insert your code here...
    unsigned char* position = (unsigned char*) stash;
    unsigned int* intvalue = NULL;
    unsigned long* doublevalue = NULL;
    unsigned char* charvalue = NULL;

    int i = 0;
    int size = 0;

    while(i < 18){
        switch(sizes[size]){
            case 1: 
                charvalue = position; 
                size++;
                cout << *charvalue << endl;       
                position++;
                i++;
                break;
            case 4:
                intvalue = (unsigned int*)position;
                size++;
                cout << *intvalue << endl;
                position += 4;
                i += 4;
                break;
            case 8:
                doublevalue = (unsigned long*)position;
                size++; 
                cout << *doublevalue << endl;
                position += 8;
                i += 8;
                break;
        }
    
    }
    return 0;
}