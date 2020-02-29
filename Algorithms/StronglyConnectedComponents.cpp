/*
In doing this lab, I used recoursece in youtube to understand 
Kosaraju's algorithm. More specifically I used this video that explained 
the concept that I implamented here.
example: stack, DFS, and transpose

Other recourses I used were lecture notes from SCC lecture. Not lecture slide
but the lecture notes for that specific lecture.
*/
#include <iostream>
#include <stack>
#include <iostream> 
#include <list> 
#include <vector>
#include <algorithm>

using namespace std;

// vector<list<int>> adjacent; //adjacency list
vector<vector<int>> adjacent;
vector<list<int>> Tadjacent;
vector<vector<int>> scc;
vector<int> status; //check if we have been there 0 for !visited, 1 for visited
vector<int> snatch;

//used this to see how my hashtable looks like for graph, I just reused my old output from lab8
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

void DFsearch2(int vertex, vector<vector<int>> Tadjacent, vector<int> &snatch){
    int size = Tadjacent[vertex].size();
    status[vertex] = 1; //marked as visited
    //Performing DFsearch for all possible routes on a vertex (adjacent[i])

        //int location = adjacent[vertex];
    for(int i = 0; i < size; i++){
        if(status[vertex] ==  0){
            DFsearch2(Tadjacent[vertex][i], Tadjacent, snatch);//recursion
        }
        else{
            continue;
        }snatch.push_back(vertex);
    }
}

// void DFsearch(int vertex, vector<vector<int>> tdarray, stack<int> &stack){
//     status[vertex] = 1; //marked as visited
//     //Performing DFsearch for all possible routes on a vertex (adjacent[i])
//     list<int>::iterator spot;
//     // for(spot = adjacent[vertex].begin(); spot != adjacent[vertex].end(); spot++){
//     for(spot = hashtable[vertex].begin(); spot != hashtable[vertex].end(); spot++){
//         //int location = adjacent[vertex];
//         if(status[*spot] ==  0){
//             DFsearch(*spot, adjacent, stack);//recursion
//         }
//         else{
//             continue;
//         }stack.push(vertex);
//     }
// }

/*old startpop*/
// void startPop(stack<int> &stack, vector<list<int>> &Tadjacent){
//     while(stack.empty() == false){  //itterates until stack is emptied out
//         int track = stack.top();    //keeps track of what is about to be popped out
//         stack.pop();
    
//     vector<int> snatch;
//         if(status[track] == 0){
//             DFsearch2(stack.top(), Tadjacent, snatch);
//             scc.push_back(snatch);
//         }
//     }
// }

void capture(vector<int> &stack, vector<vector<int>> &Tadjacent){
    for(int i = 0; i < stack.size(); i++){
        if(status[stack[i]] == 0){
            DFsearch2(stack[i], Tadjacent, snatch);
            scc.push_back(snatch);  //capturing strong connected components
        }
    }
}

//traversing through a list requires a pointer iterator. I barrowed this idea from remove function from lab8
//specifically list<int>::iterator spot; in line 29
void DFsearch(int vertex, vector<vector<int>> tdarray, vector<int> &stack){
    int size = tdarray[vertex].size();
    cout << "here 2" << endl;
    status[vertex] = 1; //marked as visited
    //Performing DFsearch for all possible routes on a vertex (adjacent[i])
    //list<int>::iterator spot;
    //for(spot = hashtable[vertex].begin(); spot != hashtable[vertex].end(); spot++){
        for(int i = 0; i < size; i++){
        //int location = adjacent[vertex];
        // if(status[*spot] ==  0){
            if(!status[tdarray[vertex][i]]){
            DFsearch(i, adjacent, stack);//recursion
        }
        // else{
        //     continue;
        // }
        stack.push_back(i);
    }
}

int main(){
    int verticies, edges; //v is # of vertices and e is the # of edges
    cin >> verticies;
    cin >> edges;
    
    adjacent.resize(verticies);

    int vertex, edge; //these are the input, not to be mistaken by sizez above
    //creating the graph
    for(int i = 0; i < edges; i++){
        cin >> vertex >> edge;
        adjacent[vertex].push_back(edge);
    }
    for(int i = 0; i < verticies; i++){
        status.push_back(0);    //0 will indicate false
    }
    //we're going to traverse the graph now
    vector<int> stack;  //this was supposed to type stack from <stack> library but kept seg faulting
                        //so instead we can just easily reverse this and it will simulate a "stack pop"
    for(int i = 0; i < verticies; i++){
        if(status[i] == 0){
            DFsearch(i, adjacent, stack);
        }
    }

    // retrieving transpose of the graph to traverse though after
    cout << "here 1" << endl;
    vector<vector<int>> Tadjacent;
    Tadjacent.resize(verticies);
    for(int i = 0; i < verticies; i++){
        //list<int>::iterator spot;
        // for(spot = adjacent[i].begin(); spot != adjacent[i].end(); spot++){
        int size = adjacent[i].size();
        for(int j = 0; j < size; j++){
            Tadjacent[adjacent[i][j]].push_back(i); //this is building the transposed adjacent list
        }
    }reverse(stack.begin(), stack.end());   //remember from the begining, we want to pop from stack
                                            //so to simulate FILO we need to reverse this array to simulate stack pop

    for(int i = 0; i < verticies; i++){
        status[i] = 0;    //0 will indicate false
    }
    //debug segfault
    //cout << "here" << endl;
    cout << "here 1" << endl;
    capture(stack, Tadjacent);
    cout << "here 1" << endl;
    //debug segfault
    //cout << "here 2" << endl;
    
    vector<int> tempA;
    tempA.resize(verticies);
    for(int i = 0; i < verticies; i++){
        tempA.push_back(i);
    }
    cout << "here 3" << endl;
    for(int i = 0; scc.size(); i++){
        cout << "here 4" << endl;
        for(int j = 0; scc[i].size(); j++){
            cout << "here 5" << endl;
            int temp = scc[i][j];
            for(int z = 0; z < verticies; z++){
                cout << "here 6" << endl;
                if(tempA[z] == temp){
                    //tempA[z] = scc[i][0];
                    tempA[z] = *min_element(scc[i].begin(), scc[i].end());
                }
            }
        }
    }

    //debug
    // for(int i = 0; i < verticies; i++){
    //     cout << tempA[i] << endl;
    // }

    for(int i = 0; i < verticies; i++){
        cout << tempA[i] << endl;
    }

    //cout << "---output for Tadjacent---" << endl;
    //output(vertex, edges, Tadjacent);
    


    //now we set the newly made Tadjacent to all false to prepare
    //traversal

    return 0;
}


//Scrap, code that I thew away but might need later?

/*

for transpose
    // for(int i = 0; i < verticies; i++){
    //     //for(list<int>::iterator j = adjacent[i].begin() ;j != adjacent[i].end(); j++){
    //     list<int>::iterator j;
    // for(j = adjacent[i].begin();j != adjacent[i].end(); j++){
    //     Tadjacent[i].push_back(i);
    //     }
    // }
    // cout << "works here" << endl;

    //debug
    //output(vertex, edges, adjacent);

*/