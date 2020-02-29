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
        //recieved help from roomate and friend in lab
        if(index < counter){
            if(counter+1 > size){    //checks if counter is equal
                int *newData = new int[size * 2];   //create a pointer newData that will be double the size of data
                int j = 0; //separate index to data incase of matching index

                for(int i = 0; j < size; i++){

                    if(i == index){
                        newData[i] = value;
                    }
                    else{
                        newData[i] = data[j++];
                    }
                }
                //zero out the rest
                for(int i = size; i < size*2; i++){
                    newData[i] = 0;
                }
                
                delete[] data;
                data = newData;
                size *= 2; 
            }
            else{
                
                // copy up to index
                int* newData = new int[size];
                for(int i = 0; i < index; i++){
                    newData[i] = data[i];
                }
                
                //insert value at index
                newData[index] = value;
                
                //copy rest
                for(int i = index + 1; i < size; i++){
                    newData[i] = data[i-1];
                }
                
                delete[] data;
                data = newData;
            }
            counter++; //elements shifted right one (including counter)
        }
        else{
            if(index <= size){
                data[index] = value; //insert value at empty index
                counter = index; //move counter up, maintain that everything to the right of counter is free
            }
            else{
                
                //copy old -> new
                int *newData = new int[size * 2];
                for(int i = 0; i < size; i++){
                    newData[i] = data[i];
                }
                
                //zero out rest
                for(int i = size; i < size*2; i++){
                    newData[i] = 0;
                }
                data = newData;
                data[index] = value;
                size *= 2;
                counter = index+1; //maintain property that everything beyond counter is free.
            }
        }
    }
    

    // Store a new value in the array
    void insert(int value){
        data[counter] = value;
        counter++;
        
        if (counter == size){
            // Just for convenience, store the old size
            int oldSize = size;
            size = size * 2;            // Let's double the amount of storage we have
            
            // Allocate another chunk of memory
            // twice as big as the first
            int* newArr = new int[size];
            
            // Copy all elements from the old location
            // to the new location
            for (int i = 0; i < oldSize; i++) {
                newArr[i] = data[i];
            }
            

            delete[] data;            // Release the old location
            

            data = newArr;            // Make our data pointer point to the new location
            
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
