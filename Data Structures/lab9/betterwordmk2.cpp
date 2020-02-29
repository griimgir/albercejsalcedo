#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
// #include <chrono>
#include "Queue.h"

using namespace std;
// using namespace std::chrono;

long K = 97;

int f(char x){
    return ((int)x - 32) % K;
}

void print(Queue** ht){
    for (long i = 0; i < K; i++) {
        cout << i << ": ";
        ht[i]->print();
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    const int N = 500000;

    Queue** hashTable = new Queue*[K];

    for(long i = 0; i < K; i++) {
        hashTable[i] = new Queue();
    }

    ifstream in("words.txt");
    
    string word;
    
    string* words = new string[N];

    int count = 0;
    
    while (in >> word) {
        words[count] = word;
        int index = f(word.at(0));
        hashTable[index]->push(word);

        count++;
    }
    
    cout << "Total: " << count << endl << endl;
    
    cout << "| Matching Progress:                      |\n|";
    int matched = 0;
    
    for (int i = 0; i < count; i++){
        string curr = words[i];
        reverse(curr.begin(), curr.end());
        char c = curr.at(0);
        int queueindex = f(c);
        if(hashTable[queueindex]->find(curr)){
            matched++;
        }
        if (i % (N/40) == 0) cout << "-";
    }
    cout << "|" << endl;
    
    
    cout << "Matched: " << matched << endl;

    for(long i = 0; i < K; i++){
        delete hashTable[i];
    }

    delete[] hashTable;
    return 0;
}
