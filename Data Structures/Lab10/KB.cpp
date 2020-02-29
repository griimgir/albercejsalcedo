#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

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
    
    
    imdb.chain("Marlon Brando", "Robert De Niro");
    imdb.chain("Sean Connery", "Harrison Ford");
    imdb.chain("Kevin Costner", "Al Pacino");
    imdb.chain("Mark Hamill", "John Cena");

//    Expected output:
//
//    Marlon Brando (The Godfather) Al Pacino (Heat) Robert De Niro
//    Sean Connery (Indiana Jones) Harrison Ford
//    Kevin Costner (The Untouchables) Robert De Niro (Heat) Al Pacino
//    Mark Hamill is not connected to John Cena
    
    return 0;
}
