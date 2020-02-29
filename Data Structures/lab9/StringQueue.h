#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <string>

struct Link {
    std::string data;
    Link* next;
    
    Link(){
        data = "";
        next = NULL;
    }
    
    Link (std::string d){
        data = d;
        next = NULL;
    }
};

struct Queue {
    Link* front;
    Link* back;
    
    Queue (){
        front = NULL;
        back = NULL;
    }
    
    std::string peek () {
        return front->data;
    }
    
    void push(std::string value){
        if (isEmpty()){
            front = new Link(value);
            back = front;
        }
        else {
            back->next = new Link(value);
            back = back->next;
        }
    }
    
    bool find (std::string value){
        // Provide your code here
        /*
        StringQueue(std::string s){
            std::string data = s
            Node next = NULL
            // This is supposed to instantiate a string queue, but idk the rest
        }
        */
        Link* temp = front;
        
        while (temp != NULL){
            if (temp->data == value){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    bool isEmpty(){
        return (front == NULL);
    }
    
    std::string pop(){
        std::string val = front->data;
        
        Link* oldFront = front;
        front = front->next;
        
        delete oldFront;
        
        return val;
    }
    
    void print() {
        // Provide your code here
        Link* temp = front;
        while (temp != NULL){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
    
    ~Queue(){
        // Provide your code here
        while(!isEmpty()){
            pop();
        }
    }
};

#endif