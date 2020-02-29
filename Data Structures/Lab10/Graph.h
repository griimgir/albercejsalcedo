#ifndef Graph_h
#define Graph_h

#include <vector>
#include <deque>

struct Vertex {
    int label;
    std::vector<int> adjList;
    
    Vertex(int label){
        this->label = label;
    }
};

struct Graph {
    std::vector<Vertex*> vertices;
    
    Graph(int size){
        vertices = std::vector<Vertex*>(size);
        for (int i = 0; i < size; i++){
            vertices[i] = NULL;
        }
    }
    
    void vertexInsert(int val){
        Vertex* v = new Vertex(val);
        vertices[val] = v;
    }
    
    void edgeInsert(int from, int to){
        vertices[from]->adjList.push_back(to);
        vertices[to]->adjList.push_back(from);
    }
    
    void print (){
        for (int i = 0; i < vertices.size(); i++){
            if (vertices[i] != NULL){
                std::cout << vertices[i]->label << ": ";
                for (int j = 0; j < vertices[i]->adjList.size(); j++){
                    std::cout << vertices[i]->adjList[j] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
    
    bool contains(std::vector<int> queue, int value){
        for (int i = 0; i < queue.size(); i++){
            if (queue[i] == value){
                return true;
            }
        }
        return false;
    }
    
    bool bfs(int start, int dest){
        std::deque<int> q;
        q.push_front(start);
        
        std::vector<int> seen;
        std::vector<int> parent(vertices.size());
        std::deque<int> path;
        
        while (!q.empty()){
            // Get the item in the front of the queue
            int curr = q.at(0);
            // and pop it off
            q.pop_front();
            
            seen.push_back(curr);
            
            std::cout << "Now visiting " << curr << std::endl;
            
            // Check if we are at the destination
            if (curr == dest){
//                for (int i = 0; i < parent.size(); i++){
//                    std::cout << i << " - " << parent[i] << std::endl;
//                }
                int temp = curr;
                
                while (temp != start){
                    path.push_front(temp);
                    temp = parent[temp];
                }
                path.push_front(temp);
                
                for (int i = 0; i < path.size(); i++){
                    std::cout << path[i] << " ";
                }
                std::cout << std::endl;
                
                return true;
            }
            
            // If we get here, it means that curr is not our destination
            // Get the actual vertex indexed by curr
            Vertex* v = vertices[curr];
            // And get a list of all its children
            std::vector<int> children = v->adjList;
            
            // Now add the children to the queue
            for (int i = 0; i < children.size(); i++){
                if (!contains(seen, children[i])){
                    q.push_back(children[i]);
                    parent[children[i]] = curr;
                    seen.push_back(children[i]);
                }
            }
        }
        
        return false;
    }
    
    
    
   
    bool dfs(int start, int dest){
        std::deque<int> q;
        q.push_front(start);
        
        std::vector<int> seen;
        std::vector<int> parent(vertices.size());
        std::deque<int> path;
        
        while (!q.empty()){
            // Get the item in the front of the queue
            int curr = q.at(0);
            // and pop it off
            q.pop_front();
            
            seen.push_back(curr);
            
            std::cout << "Now visiting " << curr << std::endl;
            
            // Check if we are at the destination
            if (curr == dest){
                //                for (int i = 0; i < parent.size(); i++){
                //                    std::cout << i << " - " << parent[i] << std::endl;
                //                }
                int temp = curr;
                
                while (temp != start){
                    path.push_front(temp);
                    temp = parent[temp];
                }
                path.push_front(temp);
                
                for (int i = 0; i < path.size(); i++){
                    std::cout << path[i] << " ";
                }
                std::cout << std::endl;
                
                return true;
            }
            
            // If we get here, it means that curr is not our destination
            // Get the actual vertex indexed by curr
            Vertex* v = vertices[curr];
            // And get a list of all its children
            std::vector<int> children = v->adjList;
            
            // Now add the children to the queue
            for (int i = 0; i < children.size(); i++){
                if (!contains(seen, children[i])){
                    q.push_front(children[i]);
                    parent[children[i]] = curr;
                    seen.push_back(children[i]);
                }
            }
        }
        
        return false;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

//
//    bool bfs (int start, int destination){
//        std::deque<int> q;
//        std::deque<int> seen;
//        std::vector<int> parent  = std::vector<int>(vertices.size());
//
//        q.push_back(start);
//        seen.push_back(start);
//
//        while(!q.empty()){
//            int curr = q.at(0);
//            q.pop_front();
//            std::cout << "Examining " << curr << std::endl;
//            if (curr == destination){
//                for (int i = 0; i < parent.size(); i++){
//                    std::cout << i << ": " << parent[i] << std::endl;
//                }
//                return true;
//            }
//
//            Vertex* v = vertices[curr];
//
//            for (int i = 0; i < v->adjList.size(); i++){
//                if (!contains(seen, v->adjList[i])){
//                    q.push_back(v->adjList[i]);
//                    seen.push_back(v->adjList[i]);
//                    parent[v->adjList[i]] = curr;
//                }
//            }
//
//        }
//
//        return false;
//    }
//
//    bool dfs (int start, int destination){
//        std::deque<int> q;
//        std::deque<int> seen;
//
//        q.push_back(start);
//        seen.push_back(start);
//
//        while(!q.empty()){
//            int curr = q.at(0);
//            q.pop_front();
//            std::cout << "Examining " << curr << std::endl;
//            if (curr == destination){
//                std::cout << "Queue: ";
//                for (int i = 0; i < q.size(); i++){
//                    std::cout << q[i] << " ";
//                }
//                std::cout << std::endl;
//                return true;
//            }
//
//            Vertex* v = vertices[curr];
//            for (int i = 0; i < v->adjList.size(); i++){
//                if (!contains(seen, v->adjList[i])){
//                    q.push_front(v->adjList[i]);
//                    seen.push_back(v->adjList[i]);
//                }
//            }
//
//        }
//
//        return false;
//    }
    
    
};

#endif /* Graph_h */
