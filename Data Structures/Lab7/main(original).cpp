#include <iostream>
#include "TimeSupport.h"
#include "RandomSupport.h"
#include "BST.h"
#include "ResizableArray.h"

using namespace std;


int main() {
    
    // Size of the problem
    long N = 100000;
    
    // We will be generating random numbers from 1 to N
    randomizer device = new_randomizer();
    uniform_distribution dist = new_distribution(1, N);
    
    cout << "Resizable Arrays" << endl << endl;
    
    ResizableArray arr;
    
    cout << "Inserting " << N << " random numbers" << endl << endl;
    
    
    cout << "| Insert Progress:                       |\n|";
    timestamp start = current_time();
    // Fill up array with N random numbers
    for (long i = 0; i < N; i++) {
        long rand = sample(dist, device);
        arr.append(rand);
        if (i % (N/40) == 0) cout << "-";
    }
    cout << "|  ";
    timestamp end = current_time();
    
    // Report how long that took
    long insertDuration = time_diff(start, end);
    cout << insertDuration << " ms" << endl << endl;
    
    
    // We will now search for all the numbers between 1 and N
    // And count how many appear out of N. This is the find rate
    long count = 0;
    cout << "| Search Progress:                       |\n|";
    timestamp searchStart = current_time();
    for (long i = 0; i < N; i++) {
        if (arr.search(i)) count++;
        if (i % (N/40) == 0) cout << "-";
    }
    cout << "|  ";
    
    timestamp searchEnd = current_time();
    
    // Report how long the search took
    long searchDuration = time_diff(searchStart, searchEnd);
    cout << searchDuration << " ms" << endl << endl;
    cout << count / (float)N * 100 << "% find rate" << endl;
    
    cout << endl;
    
    
    
    return 0;
}
