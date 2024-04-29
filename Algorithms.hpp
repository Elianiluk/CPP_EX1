#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include "Graph.hpp"

namespace ariel {
    class Algorithms {
        public:
            static int isConnected(Graph g);
            static bool isContainsCycle(Graph g); 
            static std::string shortestPath(Graph g, int des,int src);
            static std::string isBipartite(Graph g);
            static std::string negativeCycle(Graph g); 
            static bool isPath(std::vector<std::vector<int>> edges,unsigned long src,int des);
            static bool isPathHelp(std::vector<std::vector<int>> edges,unsigned long src,int des,std::vector<bool> visited);
            static bool hasCycleDFS(Graph graph, unsigned long node, std::vector<bool>& visited, std::vector<int>& parent, std::vector<std::vector<int>>& cycles);
    };
}

#endif // ALGORITHMS_HPP
