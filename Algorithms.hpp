#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include "Graph.hpp"

namespace ariel {
    class Algorithms {
        public:
            static bool isConnected(Graph g);
            static bool isContainsCycle(Graph g); 
            static std::string shortestPath(Graph g, int des, int src);
            static std::string isBipartite(Graph g);
            static bool negativeCycle(Graph g); 
            void Algorithms::DFS(Graph g,int i,std::vector<std::vector<bool>> vec1);
    };
}

#endif // ALGORITHMS_HPP
