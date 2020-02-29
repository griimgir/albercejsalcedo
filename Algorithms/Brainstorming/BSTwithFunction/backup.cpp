#include <iostream>
#include <string>
#include <cmath>
//most functions I already did in Prof. Angelo's CSE30 lab8-BST so I have reused them here in this lab
//I used stackoverflow to see how I can convert char -> int using Streams
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

Node* insert(Node* root, long value){
    // If the tree I'm inserting into is empty
    if (root == NULL){
        // Make a new node and set it to be the root
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    else{
        if (value < root->data){
            // Go left
            root->left = insert(root->left, value);
        }
        else{
            // Go right
            root->right = insert(root->right, value);
        }
    }
    
    return root;
}

// A function to find the minimum value in a tree
Node* findMin(Node* root){
    // If the current node has no left
    // Then there can't be anything in
    // the tree smaller than it
    if (root->left == NULL){
        return root;
    }
    else {
        // If on the other hand it has a left,
        // then we have not seen the smallest
        // value yet, because there are still
        // unexplored nodes to the left, and
        // we know they all have smaller values
        // than the one we are currently on
        return findMin(root->left);
    }
}

// A function to find the maximum value in a tree
Node* findMax(Node* root){
        //works the same as min but right side
    if (root->right == NULL){
        return root;
    }
    else {
        //works the same as min but right side
        return findMax(root->right);
    }
}

Node * search(Node* root, long value){
    if (root == NULL){
        // Tree is empty
        return NULL;
    }
    else{
        // Tree is not empty
        if (root->data == value){
            return root;
        }
        else if (root->data < value){
            // Go to the right
            return search(root->right, value);
        }
        else {
            // Go left
            return search(root->left, value);
        }
    }
}

int extract(string input){ //I created this function to make main() readable when debugging
    // for(int i = 0; input[i]!='\0'; i++){

    //     if(i == 1){
    //         number = (input[1] - '0');
    //     }
    //     else if(i == 2){
    //         number = (input[1] - '0') * 10 + (input[2] - '0');
    //     }
    // }
    input.erase(input.begin());
        int number = stoi(input);
    return number; 
}

int main(int argc, const char * argv[]){
    int key;
    string input; //allocating space enought to fit char inputs. 77 is my favorite number
    int condition = 1;

    while(condition == 1){ //basically while true keep looping
        cin >> input;
        

        if(input[0] == 'i'){
            //cout << input[1] << "insert" << endl;
            
            key = extract(input);
            cout << "insert number: " << key << endl;
        }//end of insert
        else if(input[0] == 'd'){
            //cout << input[1] << "delete" << endl;
            key = extract(input);
            cout << "delete number: " << key << endl;
        }//end of delete
        else if(input[0] == 'e'){
            //cout << "end" << endl;

        }//end of terminaation
        else{
            if(input[1] == 'i'){
                //cout << "Made it to 'oin'" << endl;

            }
            else{
                if(input[2] == 'r'){
                    //cout << "made it to 'opre'" << endl;

                }
                else if(input[2] == 'o'){
                    //cout << "made it to opost" << endl;

                }
            }
        }//end of tree-walk

    }//end while

    return 0;
}