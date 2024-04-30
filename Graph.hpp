#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

/*id-214787483
   name- elian iluk
   email- elian10119@gmail.com
*/
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
