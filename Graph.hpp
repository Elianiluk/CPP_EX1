#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
namespace ariel{
class Graph{
    private:
        int numOfEdges;
        std::vector<std::vector<int>> vec;
        int numOfVertices;
    public:
        Graph();
        void loadGraph(std::vector<std::vector<int>> vec1);
        void printGraph();
        int getVertices();
        int getEdges();
        std::vector<std::vector<int>> getGraph();

};
}
#endif //GRAPH_H
