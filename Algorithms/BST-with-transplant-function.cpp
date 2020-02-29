#include <iostream>
//most functions I already did in Prof. Angelo's CSE30 lab8-BST so I have reused them here in this lab
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
    // if(!node){
    //     return NULL;
    // }
    if(node->left == NULL){
        return node;
    }
    else{
        return findMin(node->left); //recurse
    }
}

//FindParent is from CSE30-lab8
Node* findParent(Node* tree, Node* node){
    if(node == tree){
        return NULL;
    }
    Node* copy = tree;     
    bool done = false;
    while(!done){
        if(copy->data <= node->data){ 
            if(copy->right->data != node->data){ 
                copy = copy->right;
            }
            else{
                done = true;
            }
        }
        else{
            if(copy->left->data != node->data){   
                copy = copy->left;
            }
            else{
                done = true;
            }
        }
    }
    return copy;
}

Node* search(Node* tree, int value){
    // If we landed on a NULL node
    // then whatever we are searching for
    // can not possibly be in the tree
    if(tree == NULL){
        //return NULL;
        //change
        return tree;
    }
    else{
        // If the current node is not NULL,
        // then there is still a chance we
        // may be able to find what we seek
        if (tree->data == value){
            // If we see the value we want, we're all set
            return tree;
        }
        else if (value < tree->data) {
            // If the value we want is smaller
            // we search for it on the left
            search(tree->left, value);
        }
        else{
            // Otherwise search for it on the right
            search(tree->right, value);
        }
    }
    return tree;
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

//I worked with Andy Alvarenga on Delete function
Node* TreeDelete(Node* tree, Node* node){
    Node* y;
    Node* parent;

    if(node->left == NULL && node->right == NULL){
        parent = findParent(tree, node);

        if(node->left == node){
            parent->left = NULL;    //deletion occurs
            delete node;
        }
        else if(parent->right == node){
            parent->right = NULL; //deletion occurs
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
    return tree;
}


int extract(string input){ //I created this function to make main() readable when debugging
    input.erase(input.begin());
    int number = stoi(input);
    return number; 
}

int main(){
    int key;
    string input; //allocating space enought to fit char inputs. 77 is my favorite number
    int condition = 1;
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
            Node* node = search(tree, key);
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