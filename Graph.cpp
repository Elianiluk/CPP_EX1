#include <iostream>
#include <vector>
#include "Graph.hpp"

/*id-214787483
   name- elian iluk
   email- elian10119@gmail.com
*/

namespace ariel {

    Graph::Graph() : numOfEdges(0), numOfVertices(0), vec() {}

    void Graph::loadGraph(std::vector<std::vector<int>> vec1) {
        if(vec1.size() != vec1[0].size()) {
            std::cout << "Invalid graph: The graph is not a square matrix." << std::endl;
            exit(1);
        }

        numOfVertices = vec1.size();
        vec = vec1;
        int countEdges = 0;
        for(unsigned long i = 0; i < vec1.size(); i++) {
            for(unsigned long j = 0;  j < vec1.size(); j++) {
                if(vec[i][j]!=0)
                    countEdges++;
            }
        }
        numOfEdges = countEdges;   
    }

    int Graph::getVertices(){
        return numOfVertices;
    }

    int Graph::getEdges(){
        return numOfEdges;
    }

    std::vector<std::vector<int>> Graph::getGraph() {
        return vec;
    }
    

    void Graph::printGraph() {
        std::cout << "Graph with " << numOfVertices << " vertices and " << numOfEdges << " edges" << std::endl;
    }

}
