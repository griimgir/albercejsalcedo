#include <iostream> 
#include <algorithm> //for search()
#include <list> //linked list
#include<iterator>  //itterator to traverse linked list
#include <vector>   //array for hashtable

using namespace std; 

void output(int value, int m, vector<list <int>> &hashtable){
    list<int>::iterator spot;   //pointer that traverse through the hashtable[index]
    for(int i = 0; i < m; i++){
        spot = hashtable[i].begin(); //points spot to the beggining of link list
        int condition = 0;
        cout << i << ":";
        while(condition != 1){
            if(spot != hashtable[i].end()){
                cout << *spot << "->";
                spot++;
            }
            else{
                cout << ";" << endl;
                condition = 1;
            }
        }
    }
}

void remove(int value, int m, vector<list <int>> &hashtable){
    list<int>::iterator spot;   //pointer that traverse through the hashtable[index]
    int index = value % m;  //finds "i"
    spot = hashtable[index].begin();
    int condition = 0;

    while(condition != 1){
        if(spot == hashtable[index].end()){
            cout << value << ":DELETE_FAILED;" << endl;
            break;
        }
        else if(*spot == value){
            hashtable[index].erase(spot);
            cout << value << ":DELETED;" << endl;
            condition = 1;
        }
        else{
            spot++;
        }
    }
}

//search function was figured out using algorithm library from https://www.geeksforgeeks.org/std-find-in-cpp/
//although instead of using a vector<> it is for a list<>
void search(int value, int m, vector<list <int>> &hashtable){
    int i = value % m; //h(k) = k % m
    list<int>:: iterator spot = find(hashtable[i].begin(), hashtable[i].end(), value);  //looks for the value between hashtable[i] -> hashtable[m] for spot to point to
    int j = distance(hashtable[i].begin(), spot); //traverse through hashtable[i] -> where spot points to, and stores that distance to as an int j
    
    if(spot != hashtable[i].end()){
        cout << value << ":FOUND_AT" << i << "," << j << ";" << endl;
    }
    else{
        cout << value << ":NOT_FOUND;" << endl;
    }
}

/*OLD search()*/
//this search would fail randomly and I can't figure it out. 
//Opting out for <algorithm> library to find value in linkedlist
/*
void search(int value, int m, vector<list <int>> &hashtable){
    list<int>::iterator spot; //spot traverse linkedList and used to print value
    int index = value % m;
    int j = 0;
    spot = hashtable[index].begin();
    int condition = 0;

    //while(spot != hashtable[index].end())
    while(condition != 1){
        if(*spot == value){
            cout << value << ":FOUND_AT" << index << "," << j << ";" << endl;
            break;
        }        
        else{
            spot++;
            j++;
        }
    }
}
*/

//&hashtable is the address to what point hashtable in main
void insert(int value, int m, vector<list <int>> &hashtable){
    int index = value % m; //h(k) = k % m
    hashtable[index].push_front(value); //finds the index in "i" and places in front of queue
}

int extract(string input){
    input.erase(input.begin());
    int number = stoi(input);
    return number; 
}

int main(){
    //declerations
    int m, value;
    string input;
    int condition = 0;
    //both these decleartion creates the hash table
    vector<list <int>> hashtable;
    //list<int>::iterator spot;   //spot traverse linkd list and used to print value

    //size of hashtable
    cin >> m;
    hashtable.resize(m);

    //if else statements to traverse through
    while(condition != 1){
        cin >> input;
        if(input[0] == 'i'){
            value = extract(input);
            insert(value, m, hashtable);
            //cout << "Value: " << value << endl;
        }
        else if(input[0] == 's'){
            value = extract(input);
            search(value, m, hashtable);
            //cout << "search: " << value << endl;
        }
        else if(input[0] == 'd'){
            value = extract(input);
            remove(value, m, hashtable);
            //cout << "delete: " << value << endl;
        }

        else if(input[0] == 'o'){
            output(value, m, hashtable);
            //cout << "output" << endl;
        }
        else{
            condition = 1;
        }
    }


    return 0;
}