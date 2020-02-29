#include <iostream>
#include <string>
//most functions I already did in CSE30 lab8-BST so I have reused them here in this lab
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Node* insert(Node* root, int value){
//     // If we have an empty root, make a new node
//     if (root == NULL){
//         root = new Node();
//         root->data = value;
//         root->left = NULL;
//         root->right = NULL;
//     }

int main(int argc, const char * argv[]){
    int key;
    char input[77]; //allocating space enought to fit char inputs. 77 is my favorite number
    int condition = 1;

    while(condition == 1){ //basically while true keep looping
        cin >> input;

        if(input[0] == 'i'){
            cout << input[1] << endl;
        }
        else if(input[0] == 'e'){
            cout << "end" << endl;
        }
        else{
            if(input[1] == 'i'){
                cout << "Made it to 'oin'" << endl;
            }
            else{
                if(input[2] == 'r'){
                    cout << "made it to 'opre'" << endl;
                }
                else if(input[2] == 'o'){
                    cout << "made it to opost" << endl;
                }
            }
        }


        // if(input[0] == "i"){

        // }

    }
    return 0;
}