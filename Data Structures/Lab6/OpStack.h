#ifndef OpStack_h
#define OpStack_h

// Define the Node struct below...

struct Node {
    int data;
    Node* next;
    char operation;
    Node(){
        data = 0;
        operation = ' ';
        next = NULL;
    }
    Node(int x, char y){
        data = x;
        operation = y;
        next = NULL;
    }
    
};

// Now define the Stack struct. It should be a stack of Nodes...

struct Stack {
    Node* head;
    Node* tail;
    int counter = 0;

    void push(int data, char operation){
        if(head == NULL){
            head = new Node(data, operation);
            tail = head;
        }
        else{
            Node* newNode = new Node(data, operation);

            tail->next = newNode;
            tail = tail->next;

        }
        counter++;
    }

    Node pop(){
            if(head != NULL){
                Node temp;
                counter--;
                //temp.data = head->data;
                temp.data = head->data;
                //temp.operation = head->operation;
                temp.operation = head->operation;
                head = head->next;
                return temp;
            }
            else{
                Node temp;
                return temp;
            }
        //if(counter != 0){
            //Node* temp;
            //temp = head;
            //nt value;
            //char op;
            //value = temp->data;
            //op = temp->operation;
            //head = temp->next;
            //delete temp;

            ////return head;
            ////counter--;
        //}
        //else{
        //    return NULL;
        //}
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

