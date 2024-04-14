#include <iostream>
#include "Graph.hpp"

namespace ariel{
    class Algorithms{
        public:
            static bool isConnected(Graph g);
            static bool isContainsCycle(Graph g); 
            static std::string shortestPath(Graph g,int des,int src);
            static std::string isBipartite(Graph g);
    };
}