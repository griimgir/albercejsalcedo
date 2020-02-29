#include <iostream>
#include "OpStack.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Stack myStack;
    
    myStack.push(5, '+');
    myStack.push(2, '-');
    myStack.push(7, '+');
    
    while (!myStack.isEmpty()) {
        Node temp = myStack.pop();
        cout << temp.data << " : " << temp.operation << endl;
    }
    
    return 0;
}
