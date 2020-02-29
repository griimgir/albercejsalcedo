#ifndef Array_h
#define Array_h

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
            std::cout << data[i] << std::endl;
        }
    }
    
    int valueAt(int index){
        return data[index];
        
    }
    
    void insertAt(int index, int value){
        if (index < size){
            for(int i = counter; i > index; i--){
                data[i] = data[i-1];
            }
            data[index] = value;
            counter++;
            if (counter == size){
                int oldSize = size;
                
                size = size * 2;
                
                int* newArr = new int[size];
                
                for (int i = 0; i < oldSize; i++) {
                    newArr[i] = data[i];
                }
                
                delete[] data;
                
                data = newArr;
            }
        }
        else{
            int oldSize = size;
            while (index > size){
                size *=2;
            }
            if (size > oldSize){
                int* newArr = new int[size];
                
                for (int i = 0; i < oldSize; i++) {
                    newArr[i] = data[i];
                }
                
                delete[] data;
                
                data = newArr;
            }
            
            for (int i = counter; i < index; i++){
                data[i] = 0;
            }
            
            data[index] = value;
            counter = index + 1;
        }
    }
    
    
    // Store a new value in the array
    void append(int value){
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


#endif
