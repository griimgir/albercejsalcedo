#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int n = 2018;


    int* p = &n;

    unsigned char* c = (unsigned char*)p;

    cout << "Address of n: " << (long) &n << endl;
    cout << "Value of p:   " << (long) p << endl;
    cout << "Value at p:   " << *p << endl;


    cout << hex << "Value at byte 1: " << (long) *c << endl;
    cout << hex << "Value at byte 2: " << (long) *(c + 1) << endl;
    cout << hex << "Value at byte 3: " << (long) *(c + 2) << endl;
    cout << hex << "Value at byte 4: " << (long) *(c + 3) << endl;

    return 0;
}
