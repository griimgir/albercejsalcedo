#ifndef BST_h
#define BST_h

struct Node {
    long data;
    
    Node* left;
    Node* right;
};

void traverse(Node* root){
    if (root != NULL){
        traverse (root->left);
        
        std::cout << root->data << std::endl;
        
        traverse(root->right);
        
    }
}

Node* insert(Node* root, long value){
    if (root == NULL){
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    else{
        if (value <= root->data){
            root->left = insert(root->left, value);
        }
        else{
            root->right = insert(root->right, value);
        }
    }
    return root;
}













bool search (Node* root, long value){
    if (root == NULL){
        return false;
    }
    else{
        if (root->data == value){
            return true;
        }
        else if (value < root->data){
            return search(root->left, value);
        }
        else {
            return search(root->right, value);
        }
    }
}



// A function to display the tree graphically
void displayTree(Node* root, int level, int direction){
    // Don't worry about this function, just use it
    if (root != NULL){
        displayTree(root->right, level+1, 1);
        
        for (int i = 0; i < level-1; i++) {
            std::cout << "   ";
        }
        if (level > 0 ){
            if (direction == 1){
                std::cout << " /--";
            }
            else{
                std::cout << " \\--";
            }
        }
        std::cout << root->data;
        std::cout << std::endl;
        level++;
        
        displayTree(root->left, level, -1);
    }
}

// Call the function to display the tree and leave some space afterwards
void drawTree(Node* root){
    displayTree(root, 0, 0);
    std::cout << std::endl << std::endl;
}


#endif 
