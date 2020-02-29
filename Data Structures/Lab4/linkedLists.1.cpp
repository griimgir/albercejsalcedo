#include <iostream>

using namespace std;

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
    
    LinkedList(){
        head = NULL;
    }
    
    void append(int value){
        
        if (head == NULL){
            head = new Node(value);
        }
        else{
            // Allocate a new node with value
            // Go to the last element of the list
            // Make the next of the last element point to the new node
            
            Node* newNode = new Node(value);
            
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            // At this point, temp is pointing to the last existing element of list
            
            temp->next = newNode;
        }
    }
    
    void insertAt(int index, int value) {
        // Provide your code here
       Node* trace = head;
       for(int i = 1; i < index; i++){
           if(trace->next != NULL){
               trace = trace->next;
           }
           else{
               Node* tempTrace = new Node(0);
               trace->next = tempTrace;
               trace = trace->next;
           }
       }
       if(trace->next != NULL){
           Node *previous = new Node;
           Node *current = new Node;
           Node *temp = new Node;
           current = head;
           int currIndex = 0;
           for(int i = 1; i <= index; i++){
               previous = current;
               current = current->next;
           }
           temp->data = value;
           previous->next = temp;
           temp->next = current;
       }
       else{
           Node* last = new Node(value);
           trace->next = last;
       }
}
    
    int getValue(int index){
        // Provide your code here
        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }
    
    void setValue(int index, int value){
        // Provide your code here
        Node* temp = head;
        for(int i = 0; i  < index+1; i++){
            if(i == index){
                temp->data = value;
                temp = temp->next;
                break;
            }
            else{
                temp = temp->next;
                continue;
            }
        }
    }
    
    void print (){
        Node* temp = head;
        
        while (temp != NULL) {
            cout << temp->data << endl;
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


int main(int argc, const char * argv[]) {
    
    LinkedList myList;
    
    
    for (int i = 0; i < 6; i++) {
        myList.append(i);
    }
    
    myList.insertAt(2, 77);
    //cout<< "test" << endl;
    myList.insertAt(10, 89);
    //cout<< "test" << endl;
    myList.append(101);
    //cout<< "test" << endl;    
    myList.setValue(0, 11);
    //cout<< "test" << endl;   
    cout << myList.getValue(2) << endl << endl;
    
    myList.print();
    
    //    Expected output:
    //    77
    //
    //    11
    //    1
    //    77
    //    2
    //    3
    //    4
    //    5
    //    0
    //    0
    //    0
    //    89
    //    101
    
    return 0;
}














