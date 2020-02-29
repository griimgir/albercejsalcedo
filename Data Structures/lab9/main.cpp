#include <iostream>
#include "Queue.h"

using namespace std;

long K = 10;

long f(long x){
    return x % K;
}


void insert(Queue** ht, long x){
    ht[f(x)]->push(x);
}

void print(Queue** ht){
    for (long i = 0; i < K; i++) {
        cout << i << ": ";
        ht[i]->print();
        cout << endl;
    }
}

bool search(Queue** ht, long x){
    return ht[f(x)]->find(x);
}


int main(int argc, const char * argv[]) {
    
    
    
    // Array of K Queues
    Queue** hashTable = new Queue*[K];
    
    // Fill up the array with K empty Queues
    for (long i = 0; i < K; i++) {
        hashTable[i] = new Queue();
    }
    
    
    insert(hashTable, 17);
    insert(hashTable, 5);
    insert(hashTable, 93);
    insert(hashTable, 97);
    
    print(hashTable);
    
    cout << search(hashTable, 93) << endl;
    

    // Delete each of the queues
    for (long i = 0; i < K; i++) {
        delete hashTable[i];
    }
    
    // Now delete the array
    delete[] hashTable;
    
    return 0;
}
