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

void preorder(Node* x){
    if(x != NULL){
        cout << x->data << endl;
        preorder(x->left);
        preorder(x->right);
    }
}

void postorder(Node* x){
    if(x != NULL){
        postorder(x->left);
        postorder(x->right);
        cout << x->data << endl;
    }
}

void inorder(Node* x){
    if(x != NULL){
        inorder(x->left);
        cout << x->data << endl;
        inorder(x->right);
    }
}

Node* insert(Node* root, int value){
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

Node* transplant(Node* tree, Node* u, Node* v){
    if(u->parent == NULL){
        return tree = v;
    }
    else if(u->parent->left == u){
        return u->parent->left = v;
    }
    else{
        return u->parent->right = v;
    }
    if(v != NULL){
        return v->parent = u->parent;
    }
}

// A function to find the minimum value in a tree
Node* findMin(Node* node){
    // if(root->left == NULL){
    //     return root;
    // }
    // else{
    //     return findMin(root->left);
    // }
    // return root;
    if(!node){
        return NULL;
    }
    while(node->left){
        node = node->left;
    }
    return node;
}

Node* findMax(Node* node){
    if(!node){
        return NULL;
    }
    while(node->right){
        node = node->right;
    }
    return node;
}

Node* successor(Node* x){
    if(x->right != NULL){
        return findMin(x->right);
    }
    Node* y = x->parent;
    while(y != NULL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

//search function, i recieved help from a friend i have who took this class previously
Node* search(Node* tree, int key){
    Node* node = tree;
    // if(x == NULL || key == x->data){
    //     return x;
    // }
    // if(key < x->data){
    //     return search(x->left, key);
    // }
    // else{
    //     return search(x->right, key);
    // }
    while(node != NULL && key != node->data){
        if(key < node->data){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    return node;
}

Node* TreeDelete(Node* tree, int key){
    Node* y;
    Node* z = search(tree, key);
    if(z->left == NULL){
       return transplant(tree, z, z->right);
    }
    else if(z-> right == NULL){
       return transplant(tree, z, z->right);
    }
    else{
        y = findMin(z->right);
        if(y->parent != z){
            y = transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
            return y;
        }
        y = transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        return y;
    }
    return tree;
}



// A function to find the maximum value in a tree
// Node* findMax(Node* root){
//         //works the same as min but right side
//     if(root->right == NULL){
//         return root;
//     }
//     else{
//         //works the same as min but right side
//         return findMax(root->right);
//     }
//     return root;
// }



// Node* search(int n) {
//     Node* x = root;
//     while (x != NULL & n != x->val) {
//         if (n < x->val)
//             x = x->left;
//         else
//             x = x->right;
//     }
//     return x;
// }

int extract(string input){ //I created this function to make main() readable when debugging
    input.erase(input.begin());
        int number = stoi(input);
    return number; 
}

int main(int argc, const char * argv[]){
    int key;
    string input; //allocating space enought to fit char inputs. 77 is my favorite number
    int condition = 1;
    // Node *node = new Node();
    Node *tree = NULL;

    while(condition == 1){ //basically while true keep looping
        cin >> input;
        

        if(input[0] == 'i'){
            //cout << input[1] << "insert" << endl;
            
            key = extract(input);
            tree = insert(tree, key);
            cout << "insert number: " << key << endl;
        }//end of insert
        else if(input[0] == 'd'){
            //cout << input[1] << "delete" << endl;
            
            key = extract(input);
            // tree->data = key;
            tree = TreeDelete(tree, key);
            cout << "delete number: " << key << endl;
        }//end of delete
        else if(input[0] == 'e'){
            //cout << "end" << endl;
            condition = 0;
        }//end of terminaation
        else{
            if(input[1] == 'i'){
                //cout << "Made it to 'oin'" << endl;
                inorder(tree);
            }
            else{
                if(input[2] == 'r'){
                    //cout << "made it to 'opre'" << endl;
                    preorder(tree);
                }
                else if(input[2] == 'o'){
                    //cout << "made it to opost" << endl;
                    postorder(tree);
                }
            }
        }//end of tree-walk

    }//end while

    return 0;
}