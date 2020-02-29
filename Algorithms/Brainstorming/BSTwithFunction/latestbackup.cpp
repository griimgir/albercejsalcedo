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

// Node* successor(Node* x){
//     if(x->right != NULL){
//         return findMin(x->right);
//     }
//     Node* y = x->parent;
//     while(y != NULL && x == y->right){
//         x = y;
//         y = y->parent;
//     }
//     return y;
// }

//FindParent is from CSE30-lab8
Node* findParent(Node* tree, Node* node){
    if (node == tree) {
        return NULL;
    }
    Node* copy = tree;     
    bool done = false;
    while (!done){
        if (copy->data <= node->data) { 
            if (copy->right->data != node->data) { 
                copy = copy->right;
            }
            else {
                done = true;
            }
        }
        else {
            if (copy->left->data != node->data) {   
                copy = copy->left;
            }
            else {
                done = true;
            }
        }
    }
    return copy;
}

Node* search(Node* node, int value){
    // If we landed on a NULL node
    // then whatever we are searching for
    // can not possibly be in the tree
    if (node == NULL){
        return node;
    }
    else{
        // If the current node is not NULL,
        // then there is still a chance we
        // may be able to find what we seek
        if (node->data == value){
            // If we see the value we want, we're all set
            return node;
        }
        else if (value < node->data) {
            // If the value we want is smaller
            // we search for it on the left
            search(node->left, value);
        }
        else{
            // Otherwise search for it on the right
            search(node->right, value);
        }
    }
    return node;
}

//exactly like psuedocode from text book except additional two lines of code to find parents.
Node* transplant(Node* tree, Node* u, Node* v){
    //parent searching
    u->parent = findParent(tree, u);
    v->parent = findParent(tree, v);

    if(u->parent == NULL){
        tree = v;
    }
    else if(u == u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }
    if(v != NULL){
        v->parent = u->parent;
    }
    return tree;
}

Node* TreeDelete(Node* tree, Node* node){
    Node* y;
    Node* parent;

    if(node->left == NULL && node->right == NULL){
        parent = findParent(tree, node);
        if(parent->right == node){
            parent->right == NULL; //deletion occurs
            delete node;
        }
        else if(node->left == node){
            parent->left = NULL;    //deletion occurs
            delete node;
        }
    }
    else if(node->left == NULL){
        tree = transplant(tree, node, node->right);
    }
    else if(node->right == NULL){
        tree = transplant(tree, node, node->left);
    }
    else{
        y = findMin(node->right);
        if(y != node->right){
            tree = transplant(tree, y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        tree = transplant(tree, node, y);
        y->left = node->left;
        y->left->parent = y;
    }
    return node;
}


//old delete function from my CSE30-lab8
// Node* TreeDelete2(Node* tree, int key){
//     Node* temp = new Node();
//     if(tree == NULL){
//         return tree;
//     }
//     else if(key > tree->data){
//         tree->right = TreeDelete(tree->right, key);
//     }
//     else if(key < tree->data){
//         tree->left = TreeDelete(tree->left, key);
//     }
//     else{
//         if(tree->right && tree->left){
//             temp = findMin(tree->right);
//             tree->data = temp->data;
//             tree->right = TreeDelete(tree->right, temp->data);
//         }
//         else{
//             temp = tree;
//             if(tree->left = NULL){
//                 tree = tree->right;
//             }
//             else if(tree->right == NULL){
//                 tree = tree->left;
//             }
//         }
//     }
//     // delete temp;
//     return tree;
// }


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
    Node* node = new Node();
    Node* tree = NULL;

    while(condition == 1){ //basically while true keep looping
        cin >> input;
        

        if(input[0] == 'i'){
            //cout << input[1] << "insert" << endl;
            
            key = extract(input);
            tree = insert(tree, key);
            // cout << "insert number: " << key << endl;
        }//end of insert
        else if(input[0] == 'd'){
            //cout << input[1] << "delete" << endl;
            
            key = extract(input);
            node = search(tree, key);
            tree = TreeDelete(tree, node);
            // cout << "delete number: " << key << endl;
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