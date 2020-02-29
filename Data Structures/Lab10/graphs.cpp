#include <iostream>
#include <map>
#include "Graph.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Graph g = Graph(8);
    
    g.vertexInsert(0);
    g.vertexInsert(1);
    g.vertexInsert(2);
    g.vertexInsert(3);
    g.vertexInsert(4);
    g.vertexInsert(5);
    g.vertexInsert(6);
    g.vertexInsert(7);
    
    g.edgeInsert(0, 1);
    g.edgeInsert(0, 3);
    g.edgeInsert(1, 3);
    g.edgeInsert(1, 4);
    g.edgeInsert(1, 2);
    g.edgeInsert(2, 4);
    g.edgeInsert(2, 5);
    g.edgeInsert(3, 6);
    
    g.print();
    
    int start = 0;
    int dest = 5;
    
    cout << g.dfs(start, dest) << endl;

    
    return 0;
}
