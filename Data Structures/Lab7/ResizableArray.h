#ifndef ResizableArray_h
#define ResizableArray_h

struct ResizableArray {
    // This is the poiner to the start of our array
    long* data;
    
    // Keep track of how much memory we have allocated
    long size;
    
    // Keep track of how much memory we have used
    long counter;
    
    // A default constructor
    ResizableArray(){
        // Start off by allocating memory for 1 int
        data = new long[1];
        
        // This means we have allocated for 1
        size = 1;
        
        // And we are currently using 0
        counter = 0;
    }
    
    // Print the contents we have
    void print(){
        for (long i = 0; i < counter; i++){
            std::cout << data[i] << std::endl;
        }
    }
    
    long valueAt(long index){
        return data[index];
        
    }
    
    void insertAt(long index, long value){
        if (index < size){
            for(long i = counter; i > index; i--){
                data[i] = data[i-1];
            }
            data[index] = value;
            counter++;
            if (counter == size){
                long oldSize = size;
                
                size = size * 2;
                
                long* newArr = new long[size];
                
                for (long i = 0; i < oldSize; i++) {
                    newArr[i] = data[i];
                }
                
                delete[] data;
                
                data = newArr;
            }
        }
        else{
            long oldSize = size;
            while (index > size){
                size *=2;
            }
            if (size > oldSize){
                long* newArr = new long[size];
                
                for (int i = 0; i < oldSize; i++) {
                    newArr[i] = data[i];
                }
                
                delete[] data;
                
                data = newArr;
            }
            
            for (long i = counter; i < index; i++){
                data[i] = 0;
            }
            
            data[index] = value;
            counter = index + 1;
        }
    }
    
    bool search(long value){
        for (long i = 0; i < counter; i++){
            if (data[i] == value){
                return true;
            }
        }
        return false;
    }
    
    bool binarySearch(long value, long start, long end){
        
        if (start >= end){
            return false;
        }
        long mid = ((end - start) / 2) + start;
        
        if (data[mid] == value){
            return true;
        }
        else{
            if (data[mid] > value){
                return binarySearch(value, start, mid);
            }
            else{
                return binarySearch(value, mid+1, end);
            }
        }
    }
    
    bool fastSearch(long value){
        return binarySearch(value, 0, counter);
    }
    
    void sortedInsert(long value){
    
        append(value);
        
        long last = counter-1;
        
        while(last > 0 && data[last] < data[last-1]){
            long temp = data[last-1];
            data[last-1] = data[last];
            data[last] = temp;
            last--;
        }
    }
    
    
    
    // Store a new value in the array
    void append(long value){
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
            long oldSize = size;
            
            // Let's double the amount of storage we have
            size = size * 2;
            
            // Allocate another chunk of memory
            // twice as big as the first
            long* newArr = new long[size];
            
            // Copy all elements from the old location
            // to the new location
            for (long i = 0; i < oldSize; i++) {
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
