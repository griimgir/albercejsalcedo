#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

//reference materials used to understand this topic were a video on youtube and GeeksforGeeks
//https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
//https://www.youtube.com/watch?v=0kNXhFIEd_w

//Worked on lab with Andy Alvarenga 
//I recieved help from Patrick Doran by conceptually teaching me about
//using priority queue as a way to do the minHeap and creating the traverse function

using namespace std;

struct HeapNode{
    char letter = ' ';
    int frequency = 0;
    //vector<int> output;
    string container = "";
    HeapNode *left = NULL, *right = NULL;
};

//this sort stack is from geeks4geeks, just wanted a way to have stack store least to greatest.
//I'm using this instead of priority queue
void sortStack(stack<HeapNode*> &stak){ 
    stack<HeapNode*> tempStack; 
    HeapNode* tmp;
    while (!stak.empty()){ 
        // pop first element 
        tmp = stak.top(); 
        stak.pop(); 
  
        while (!tempStack.empty() && tempStack.top() > tmp){ 
            stak.push(tempStack.top()); 
            tempStack.pop(); 
        }
        tempStack.push(tmp); 
    } 
    //return tempStack; 
} 

//void traverse(HeapNode* &tree, , vector<vector<int>> &container, vector<int> &freqList, int size){
 void traverse(HeapNode* tree, string numbers, string container[], vector<int> freqList){
     int size = 6;
    // cout << "test" << endl;
    if(tree == NULL){
        return;
    }
    else if(tree->letter == ' '){
        traverse(tree->left, numbers + "0", container, freqList);
        // cout << "test2" << endl;
        traverse(tree->right, numbers + "1", container, freqList);
    }
    //base case
    else{
        for(int i = 0; i < size; i++){
            if(tree->frequency == freqList[i]){
                //container[i].push_back(numbers);
                container[i] = numbers;
            }
        }
    }

}

//this is a helper function to create a ordered queue, similar to a stack
struct compare{
    bool operator()(const HeapNode* A, const HeapNode* B) const{
        return A->frequency > B->frequency;
    }
};

void huffman(HeapNode* &tree, vector<int> &freqList, int size){
    //stack<HeapNode*> stak;
    priority_queue<HeapNode*, vector<HeapNode*>, compare> stak;
    //HeapNode* node = new HeapNode();
    for(int i = 0; i < size; i++){
        HeapNode* node = new HeapNode();
        node->frequency = freqList[i];
        node->letter = 'A' + i;
        stak.push(node);
    }
    //sort the stack
    //sortStack(stak);
    while(stak.size() != 1){
        HeapNode* z = new HeapNode();
        //Psuedo code was provided in Intro to algorithms book
        HeapNode* left = stak.top();
        stak.pop();
        z->left = left;
    //straight from the book
        HeapNode* right = stak.top();
        stak.pop();
        z->right = right;

        z->frequency = right->frequency + left->frequency;
        stak.push(z);
    }
    tree = stak.top();

    string numbers = "";
    string container[6];

    traverse(tree, numbers, container, freqList);

        for(int i = 0; i < 6; i++){
        cout << char('A' + i) << ":" << container[i] << endl;
    }
}

void output(string container[], int size){
    for(int i = 0; i < size; i++){
        cout << char('A' + i) << ":" << container[i] << endl;
    }
}

int main(){
    int input;
    vector<int> freqList;
    
    
    /*
    I mistakenly thought it would just resize, not just make zeros
    */
    //freqList.resize(6);
    for(int i = 0; i < 6; i++){
        cin >> input;
        freqList.push_back(input);
    }

    // for (int i = 0; i <6; i++){
    //     cout << freqList[i] << endl;
    // }

    //cout << "test" << endl;
    HeapNode* tree = new HeapNode();
    //cout << "test2" << endl;
    huffman(tree, freqList, 6);
    return 0;


//     //cout << "test3" << endl;
//     // vector<vector<int>> container;
//     // container.resize(6);
//     // int* numbers;

//     //Andy and Patrick helpred here. Instead of passing a vector int just pass an string
//     // string is technically a char array
//     string numbers = "";
//     string container[6];

//     //container.resize(6);
//     //now we traverse through the tree

//     //traverse(tree, numbers, container, freqList, 6);
//     //cout << "test4" << endl;
//     traverse(tree, numbers, container, freqList);
// //cout << "Pass the segfault" << endl;
//     //output(container ,6);

    // return 0;
}