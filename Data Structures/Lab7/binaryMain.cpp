#include <iostream>
#include "TimeSupport.h"
#include "RandomSupport.h"
#include "BST.h"
#include "ResizableArray.h"

using namespace std;

int main() {
//Size of the problem
long N = 100000;

//number generator from 1- N
randomizer device = new_randomizer();
uniform_distribution dist = new_distribution(1, N);

cout << "Binary Trees" << endl << endl;

Node* root = NULL;

cout << "Inserting " << N << " random numbers" << endl << endl;

cout << "| Insert Progress:                       |\n|";
timestamp start = current_time();
//inserts to binary
for (long i = 0; i < N; i++){
    long stuff = sample(dist, device);
    root = insert(root, stuff);
    if (i % (N/40) == 0) cout << "-";
}
cout << "|  ";
timestamp end = current_time();

// Report how long that took
long insertDuration = time_diff(start, end);
cout << insertDuration << " ms" << endl << endl;

//searching
long count = 0;
cout << "| Search Progress:                       |\n|";
timestamp searchStart = current_time();
for (long i = 0; i < N; i++) {
    long stuff = sample(dist, device);
    if (search(root, stuff)){ count++;}
    if (i % (N/40) == 0){ cout << "-";}
}
cout << "|  ";
    
timestamp searchEnd = current_time();
    
// Report how long the search took
long searchDuration = time_diff(searchStart, searchEnd);
cout << searchDuration << " ms" << endl << endl;
cout << count / (float)N * 100 << "% find rate" << endl;
    
cout << endl;

delete root;
return 0;
}
