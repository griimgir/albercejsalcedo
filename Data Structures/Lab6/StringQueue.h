
#ifndef Queue_h
#define Queue_h

#include <string>

struct Node {
    // Provide your code here...
    std::string data;
    Node* next;

    Node(){
        data = "";
        next = NULL;
    }
    
    Node(std::string x){
        data = x;
        next = NULL;
    }
};

struct Queue {
    // Provide your code here...
    Node* head;
    Node* tail;
    int counter = 0;

    Queue(){
        head = 0;
        tail = NULL;
    }
    void push(std::string data){
        if(head == NULL){
            head = new Node(data);
            tail = head;
        }
        else{
            Node* newNode = new Node(data);

            tail->next = newNode;
            tail = tail->next;

        }
        counter++;
        //Node* newNode;
        //newNode = tail->data;        
        //tail->next = newNode;
        //tail = newNode;
        //counter++;
    }
    std::string pop(){
        if(counter != 0){
        Node* temp;
        temp = head;
        std::string value;
        value = temp->data;
        head = temp->next; 
        delete temp;

        return value;
        counter--;
        }

        else{
            return NULL;
        }
    }
    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        else{
            false;
        }
    }
};

#endif


