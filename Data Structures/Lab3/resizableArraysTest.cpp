#include <iostream>

using namespace std;

struct ResizableArray {
    // This is the poiner to the start of our array
    int* data;
    
    // Keep track of how much memory we have allocated
    int size;
    
    // Keep track of how much memory we have used
    int counter;
    
    // A default constructor
    ResizableArray(){
        // Start off by allocating memory for 1 int
        data = new int[1];
        
        // This means we have allocated for 1
        size = 1;
        
        // And we are currently using 0
        counter = 0;
    }
    
    // Print the contents we have
    void print(){
        for (int i = 0; i < counter; i++){
            cout << data[i] << endl;
        }
    }
    
    int getValueAt(int index){
        // Provide your code here
        int getValue = data[index]; //getValue will now store whata ever is at data[index]
        return getValue;
    }
    
    void setValueAt(int index, int value){
        // Provide your code here
        data[index] = value;    //data will now be stored into value
    }
    
    void insertAt(int index, int value){
        // Provide your code here


        if(index <= size){
            size++;
            counter++;
            
            int* insert;
            insert = new int[size];
            
            for(int i = 0; i < index; i++){
                insert[i] = data[i];
            }

            insert[index] = value;

            for(int i = index + 1; i <= size; i++){
                insert[i] = (data[i - 1]);
            }
            data = insert;
        }
        else if(size < index){
            size++;
            counter++;
        int *insert = new int[size]; 
        for(int i = 0; i <= size; i++){
            insert[i] = data[i];
        }
        for(int i = size + 1; i < index; i++){
            insert[i] = 0;
        }
        insert[index] = value;
        }
    }
    
    // Store a new value in the array
    void insert(int value){
        // The very first time this is called
        // we know we have enough storage allocated
        // because we allocated space for 1 int
        // so we store it
        data[counter] = value;
        // and increase the counter
        counter++;
        
        // If we are out of space, i.e. we have
        // stored as much as we have allocated
        // then we need to increase our storage space
        if (counter == size){
            // Just for convenience, store the old size
            int oldSize = size;
            
            // Let's double the amount of storage we have
            size = size * 2;
            
            // Allocate another chunk of memory
            // twice as big as the first
            int* newArr = new int[size];
            
            // Copy all elements from the old location
            // to the new location
            for (int i = 0; i < oldSize; i++) {
                newArr[i] = data[i];
            }
            
            // Release the old location
            delete[] data;
            
            // Make our data pointer point to the new location
            data = newArr;
            
        }
    }
};


int main(int argc, const char * argv[]) {
    // Create a resizable array
    ResizableArray array;
    
    for (int i = 0; i < 6; i++) {
        array.insert(i);
    }
    
    array.insertAt(2, 77);
    
    array.insertAt(10, 89);
    
    array.insert(101);
    
    // Print out the array
    array.print();
    
    /* Expected output of array.print()
     0
     1
     77
     2
     3
     4
     5
     0
     0
     0
     89
     101
    */
    
    cout << "count: " << array.counter << endl;
    cout << "size : " << array.size << endl;
    
    /* Expected output of 2 lines above
     
     count: 12
     size : 16
    
    */
    
    return 0;
}
