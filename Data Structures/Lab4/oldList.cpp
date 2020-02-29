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

int getValueAt(int index){
    int value = data[index];
    return value;
}

void setValueAt(int index, int value){
    data[index] = value; 
}

insertAt(int index, int value){
    
}

int main(int argc, const char * argv[]) {
    
    LinkedList myList;
    
    
    for (int i = 0; i < 6; i++) {
        myList.append(i);
    }
    
    myList.insertAt(2, 77);
    
    myList.insertAt(10, 89);
    
    myList.insert(101);
    
    
    myList.print();
    
    return 0;
}














