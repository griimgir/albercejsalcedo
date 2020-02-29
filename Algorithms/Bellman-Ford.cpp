#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h> //use for INT_MAX
//I worked with Andy Alvarenga on this lab. We used outside recourse to understand graph conepts
//from geeksforgeeks https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

using namespace std;

//worked with Andy Alvarenga with function structures. We both had studied a similar concept from geeksforgeeks
struct edge{
    int start, destination; //source -> destination variable declarations
    int weights;
};
struct graphstruct{
    //note these represent the # of verticies and edges
    int V, E;
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

void addEdges(int size, struct graphstruct* &graph){
    for(int i = 0; i <= size; i++){
        int vertex, edge, weight;
        cin >> vertex >> edge >> weight;

        graph->edge[i].start = vertex;
        graph->edge[i].destination = edge;
        graph->edge[i].weights = weight;
    }
}

void output(struct graphstruct* &graph, int tracker[], int condition){
    int start, end, weight;
    for(int i = 0; i < graph->E; i++){
        start = graph->edge[i].start;
        end = graph->edge[i].destination; 
        weight = graph->edge[i].weights;

            int compareMax = tracker[start];
            int compareWeight = tracker[start] + weight;
            if(compareMax != INT_MAX && tracker[end] > compareWeight){
                condition = 0;
            }
            else if(i == ((graph->E) - 1)){
                condition = 1;
            }
        }
    
    //case 1
    if(condition == 1){
        cout << "TRUE" << endl;
        for(int i = 0; i < graph->V; i++){
            int track = tracker[i];
            if(track == INT_MAX){
                cout << "INFINITY" << endl;
            }
            else{
                cout << track << endl;
            }
        }
    }
    //case 2 where condition = 0
    else{
        cout << "FALSE" << endl;
    }
}



void bellmanFord(struct graphstruct* &graph, int src){
    int tracker[graph->V];
    for(int i = 0; graph->V; i++){
        tracker[i] = INT_MAX;
    }

    for(int i = 1; i < graph->V; i++){
        for(int j = 0; j < graph->E; j++){
            int start, end, weight;

            start = graph->edge[j].start;
            end = graph->edge[j].destination;
            weight = graph->edge[j].weights;

            int compareMax = tracker[start];
            int compareWeight = tracker[start] + weight;
            if(compareMax != INT_MAX && tracker[end] > compareWeight){
                tracker[end] = compareWeight;
            }
        }
    }
    output(graph, tracker, 0);
}

int main(){
    //# of verticies and # of edges NOT to be be mistaken by edge and vertex inputs
    int verticies, edges;

    //input for number of verticies
    cin >> verticies >> edges;

    //creating a graph
    struct graphstruct* graph = create(verticies, edges);

    //input edges
    int size = edges - 1;
    addEdges(size, graph);

    //know to initiate Bellman–Ford Algorithm
    //we need to prepare the start which is the source and create an array
    //which will keeo track if the distance. Concept from this video on youtube
    //which also provided a pseudo code https://www.youtube.com/watch?v=obWXjtg0L64
    int src = 0;
    bellmanFord(graph, src);

    return 0;
}