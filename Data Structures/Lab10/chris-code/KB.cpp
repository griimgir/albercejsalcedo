#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;




//Updated Graph.h to take in strings as data for vertices, and edges store data of movie connecting two actors

struct Edge{
    string vertex;
    string label;
    Edge(string label,string vertex)
    {
        this->vertex=vertex;
        this->label=label;
    }
};

struct Vertex
{
    std::string label;
    std::vector<Edge*> adjList;

    Vertex(std::string label)
    {
        this->label = label;
    }
};

struct Pairs{
    string vertex;
    string Edges;

};

struct Triple{
    string parent;
    string vertex;
    string label;

    Triple(string parent, string vertex, string label){

    }
};

struct Graph
{
    std::vector<Vertex*> vertices;

    Graph()
    {
    }

    void vertexInsert(std::string val)
    {
        Vertex *v = new Vertex(val);
        vertices.push_back(v);
    }

    // // edge insert without edge labels
    //
     void edgeInsert(string label, string from, string to){

         int src=0,dst=0;
         for (int i = 0; i < vertices.size(); i++)
         {
             if(vertices[i]->label==from)
             {
                 src=i;
             }
             if(vertices[i]->label==to)
             {
                 dst=i;
             }
             /* code */
         }
         
         
         vertices[src]->adjList.push_back(new Edge(label, to));
         vertices[dst]->adjList.push_back(new Edge(label, from));
    }

    void print()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i] != NULL)
            {
                std::cout << vertices[i]->label << ": ";
                for (int j = 0; j < vertices[i]->adjList.size(); j++)
                {
                    std::cout << vertices[i]->adjList[j]->label << " ";
                }
                std::cout << std::endl;
            }
        }
    }

        bool contains(std::vector<string> queue, string value)
    {
        for (int i = 0; i < queue.size(); i++)
        {
            if (queue[i] == value)
            {
                return true;
            }
        }
        return false;
    }

    bool chain(string start, string dest)
    {
        std::deque<std::string> q;
        q.push_front(start);

        std::vector<std::string> seen;
        std::vector<Triple*> parent(vertices.size());
        std::deque<std::string> path;

        while (!q.empty())
        {
            // Get the item in the front of the queue
            string curr = q.at(0);
            // and pop it off
            q.pop_front();

            seen.push_back(curr);

            std::cout << "Now visiting " << curr << std::endl;

            // Check if we are at the destination
            if (curr == dest)
            {
                //                for (int i = 0; i < parent.size(); i++){
                //                    std::cout << i << " - " << parent[i] << std::endl;
                //                }
                string temp = curr;

                while (temp != start)
                {
                    path.push_front(temp);
                    temp = parent[temp];
                }
                path.push_front(temp);

                for (int i = 0; i < path.size(); i++)
                {
                    std::cout << path[i] << " ";
                }
                std::cout << std::endl;

                return true;
            }

            // If we get here, it means that curr is not our destination
            // Get the actual vertex indexed by curr
            Vertex* v = vertices[curr];
            // And get a list of all its children
            std::vector<std::string> children = v->adjList;

            // Now add the children to the queue
            for (int i = 0; i < children.size(); i++)
            {
                if (!contains(seen, children[i]))
                {
                    q.push_back(children[i]);
                    parent[children[i]] = curr;
                    seen.push_back(children[i]);
                }
            }
        }

        return false;
    }
};
// Provide the definition for Graph here, along with anything else you need to make it work...

int main(int argc, const char * argv[]) {
    
    // The graph that stores the movie database
    Graph imdb;
    
    
    // Each actor is a vertex
    imdb.vertexInsert("Al Pacino");
    imdb.vertexInsert("Robert De Niro");
    imdb.vertexInsert("Marlon Brando");
    imdb.vertexInsert("Mark Hamill");
    imdb.vertexInsert("Harrison Ford");
    imdb.vertexInsert("Sean Connery");
    imdb.vertexInsert("Kevin Costner");
    imdb.vertexInsert("John Cena");
    
    // If two actors have been in a movie together,
    // they are connected by an edge
    // The edge is labelled witht the name of the movie
    
    imdb.edgeInsert("The Godfather", "Al Pacino", "Marlon Brando");
    imdb.edgeInsert("Heat", "Al Pacino", "Robert De Niro");
    
    imdb.edgeInsert("Star Wars", "Mark Hamill", "Harrison Ford");
    imdb.edgeInsert("Indiana Jones", "Harrison Ford", "Sean Connery");
    imdb.edgeInsert("The Untouchables", "Sean Connery", "Kevin Costner");
    imdb.edgeInsert("The Untouchables", "Robert De Niro", "Kevin Costner");
    imdb.edgeInsert("The Untouchables", "Robert De Niro", "Sean Connery");
    
    imdb.print();
    // imdb.chain("Marlon Brando", "Robert De Niro");
    // imdb.chain("Sean Connery", "Harrison Ford");
    // imdb.chain("Kevin Costner", "Al Pacino");
    // imdb.chain("Mark Hamill", "John Cena");

//    Expected output:
//
//    Marlon Brando (The Godfather) Al Pacino (Heat) Robert De Niro
//    Sean Connery (Indiana Jones) Harrison Ford
//    Kevin Costner (The Untouchables) Robert De Niro (Heat) Al Pacino
//    Mark Hamill is not connected to John Cena
    
    return 0;
}