#include <iostream>
#include "RandomSupport.h"
#include "TimeSupport.h"

using namespace std;

// A function that performs linear search through an array
bool search(long* arr, long n, long val){
    // Go through the whole array
    for (long i = 0; i < n; i++) {
        // If you found the value you want, stop and return
        if (arr[i] == val){
            return true;
        }
    }
    // If you complete the loop and have not returned
    // that means the value you are looking for is not there
    return false;
}


int main() {
    // How big should our array be
    long N = 100000000;
    
    // How many times should we perform the search
    long searches = 1000;
    
    // Declare the array as a pointer to a location
    // big enough to store N long integers
    long* arr = new long[N];
    
    // Setup a random number generator (randomizer)
    randomizer device = new_randomizer();
    // Set up a distribution to sample from, ranging 1 to N
    uniform_distribution dist = new_distribution(1, N);
    
    timestamp insertStart = current_time();
    // Fill up the array with N random numbers
    for (long i = 0; i < N; i++) {
        long rand = sample(dist, device);
        arr[i] = rand;
    }
    
    timestamp insertEnd = current_time();
    
    // Get a timestamp before starting the searches
    timestamp start = current_time();
    
    // Perform as many searches as specified above,
    // always for a value we know is not in the list
    // forcing the search to do as much work as possible
    for (int i = 0; i < searches; i++){
        bool temp = search(arr, N, -1);
        if (temp){
            cout << "Found." << endl;
        }
    }
    
    // Get a timestamp right after you're done searching
    timestamp end = current_time();
    
    // How much time passed between the two timestamps
    long duration = time_diff(start, end);
    
    long insertDuration = time_diff(insertStart, insertEnd);
    
    cout << "Took " << insertDuration << " milliseconds to insert." << endl;
    
    // Print out the duration
    cout << "Took " << duration << " milliseconds." << endl;
    
    // Release the memory occupied by the array
    // This is important
    delete[] arr;
}
