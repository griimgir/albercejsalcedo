#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include <utility>
#include <queue>
#define MAX_INT 2147483647 //from lab 0
#define ArrSize 9999    //this is to initiate array sizes becuase vectors weren't working and i have no idea why
// #define graphsize 9999
// vector <pair<int, int>> graph[graphsize];
using namespace std;

//Worked together with Jaeha, Patrick, and Andy Alvarenga, and upperclassman
//note old way didn't work, only functions being used are new_build, and new_prim

struct edge{
    int start, destination; //source -> destination variable declarations
    int weights;
};
struct graphstruct{
    //note these represent the # of verticies and edges
    int V;
    int E;
    //not to be mistaken by # of edges, tis is an array of edges
    struct edge* edge;
};
struct graphstruct* create(int verticies, int edges){
    struct graphstruct* graph = new graphstruct; //creating a graph
    graph->V = verticies;
    graph->E = edges;

    graph->edge = new edge[edges];
    return graph;
};

void debugGraph(graphstruct* graph){
    cout << "----------DEBUG----------" << endl;
    for(int i = 0; i < graph->V; i++){
        for(int j = 0; i < graph->E; i++){
            cout << graph->edge[i].start << " " <<
            graph->edge[i].destination << " "   <<
            graph->edge[i].weights << endl;
        }
    }
    cout << "----------DEBUG----------" << endl;
}

void new_build(vector <vector<pair<int, int>>> &graph, int verticies, int edges){
    for(int i = 0; i < edges; i++){
        int source, destination, weight;
        cin >> source >> destination >> weight;
        
        graph[source].push_back(make_pair(destination, weight));    //this time im connecting
        graph[destination].push_back(make_pair(source, weight));    //source and destination with their weights
    }                                                               //instead of creating a struct that carries an edge vector
}

void build(graphstruct* &graph){
    for(int i = 0; i < graph->V; i++){
        for(int j = 0; i < graph->E; i++){
            int source, destination, weight;
            cin >> source >> destination >> weight; //weghts represent both the edge and the weight

            graph->edge[i].start = source;
            graph->edge[i].destination = destination;
            graph->edge[i].weights = weight;
        }
    }
    //debugGraph(graph);
}

int min(int key[], bool check[], int V){
    int min = INT_MAX;
    int minI;

    for(int i = 0; i < V; i++){
        if(check[V] == false && key[V] < min){
            min = key[V];
            minI = V;
        }
    }
    return minI;
}

void output(int *parent, int size){
    for(int i = 1; i < size; i++){
        cout << parent[i] << endl;
    }
}

//new prim new_prim(graph, check, parent, key, verticies, edges);
void new_prim(vector<pair<int, int>> graph[], int *check, int *parent, int *key, int verticies, int edges){
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> queue;
    queue.push(pair<int, int> (0, 0));
    //initializes infitnity to vector
    //cout << "made it 2" << endl;
    for(int i = 0; i < verticies; i++){
        parent[i] = 0;
        // key.push_back(MAX_INT);
        key[i] = INT_MAX;
    }
    //cout << "made it 3" << endl;
    while(queue.empty() == false){
        //we store mimimum then pop the stack, well in this case a queue. 
        //Will be reffereing queue as stack from here on out
        int minimum = queue.top().second;
        //pop queue until it's empty, this solved my infinite loop itteration
        queue.pop();
    //cout << "made it 4" << endl;
        // check[minimum] = true;
        check[minimum] = true;
        int size = graph[minimum].size();
        //cout << size << endl;
        for(int i = 0; i < size; i++){
            //cout << "made it 5" << endl;
            //cout << "size is: " << size << endl;
            int vertex, weight;
            vertex = graph[minimum][i].first;
            weight = graph[minimum][i].second;
            //alright so instead of tracking source and what not just know where to and the wight
            //cout << "made it 5.5" << endl;
            if(key[vertex] > weight && check[vertex] == false){
                parent[vertex] = minimum;
                key[vertex] = graph[minimum][i].second;
                queue.push(pair<int, int> (weight, vertex));
            }
        }
    }
    output(parent, verticies);
}

//old prim
void primInitially(graphstruct* &graph){
    int parent[graph->V];   //store MST
    int key[graph->E];      //store minimum weights

    bool check[graph->V];
    //initiialize each entry to infinity
    for(int i = 0; i < graph->V; i++){
        key[i] = INT_MAX;
        check[i] = false;
    }
        key[0] = 0;
        parent[0] = graph->edge[0].start;
    int size = (graph->V) - 1;
    for(int i = 0; i < size; i++){
        int minimum = min(key, check, graph->V);
        check[minimum] = true;
        for(int j = 0; j < graph->V; j++){
            if(graph->edge[minimum].destination && check[j] == false && graph->edge[minimum].destination < key[j]){
                parent[j] = minimum;
                key[j] = graph->edge[minimum].destination;
            }
        }
    }
    for(int i = 1; i < graph->V; i++){
    }
}

int main(){
    int verticies, edges;   //input sizes
    cin >> verticies;
    cin >> edges;

    int check[ArrSize];
    int parent[ArrSize];
    int key[ArrSize];

    //graphstruct* graph = create(verticies, edges);
    //build(graph);
    //vector <pair<int, int>> graph[verticies];
    //vector <vector<pair<int, int>>> graph;
    vector<pair<int, int>> graph[ArrSize];
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> queue;
    //new_build(graph, verticies, edges);
        int source, destination, weight;
    for(int i = 0; i < edges; i++){
        cin >> source >> destination >> weight;
        
        graph[source].push_back(make_pair(destination, weight));    //this time im connecting
        graph[destination].push_back(make_pair(source, weight));    //source and destination with their weights
    }
    //cout << "made it" << endl;
    new_prim(graph, check, parent, key, verticies, edges);

    //debugGraph(graph);
    //prim(graph);

    //output(parent, verticies);

    return 0;
}