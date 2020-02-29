#ifndef LinkedList_h
#define LinkedList_h

struct Node {
    int data;
    Node* next;
    
    Node(){
        data = 0;
        next = NULL;
    }
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


struct LinkedList {
    Node* head;
    Node* last;
    
    int size;
    LinkedList(){
        head = NULL;
        last = NULL;
        size = 0;
    }
    
    int valueAt(int index){
        int count = 0;
        Node* curr = head;
        while (count < index){
            curr = curr->next;
            count++;
        }
        return curr->data;
    }
    
    void append(int value){

        if (head == NULL){
            head = new Node(value);
            last = head;
        }
        else{
            // Allocate a new node with value
            // Go to the last element of the list
            // Make the next of the last element point to the new node

            Node* newNode = new Node(value);

            last->next = newNode;
            last = last->next;

        }
        size++;
    }
    
    void insertAt(int index, int value) {
        // Provide your code here
        
        if (index == 0){
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
        else {
            
            Node* temp = head;
            
            for (int i=0; i < index-1; i++){
                if (temp->next == NULL){
                    Node* dummy = new Node(0);
                    temp->next = dummy;
                }
                temp = temp->next;
            }
            
            Node* oldNext = temp->next;
            
            Node* newNode = new Node(value);
            
            temp->next = newNode;
            newNode->next = oldNext;
        }
    }
    
    void print (){
        Node* temp = head;
        
        while (temp != NULL) {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
    
    ~LinkedList(){
        Node* temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            delete head;
            head = temp;
        }
    }
};

#endif
