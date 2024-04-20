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
            static bool negativeCycle(Graph g); 
            static bool isPath(std::vector<std::vector<int>> edges,unsigned long src,int des);
            static bool isPathHelp(std::vector<std::vector<int>> edges,unsigned long src,int des,std::vector<bool> visited);
            // static bool isContainsCycleUtil(Graph g, unsigned long v, std::vector<bool>& visited, std::vector<bool>& recStack);
            // static void printCycle(Graph g, unsigned long start, int end);

    };
}

#endif // ALGORITHMS_HPP
