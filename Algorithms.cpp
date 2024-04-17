#include "Algorithms.hpp"
#include <queue>
#include <vector>

namespace ariel {

    void Algorithms::DFS(Graph g,int i,std::vector<std::vector<bool>> vec1)
    {
        
    }
    bool Algorithms::isConnected(Graph g) {
        int numVertices=g.getVertices();
        std::vector<std::vector<bool>> matrix(numVertices, std::vector<bool>(numVertices, false));
        for(int i=0;i<numVertices;i++)
            DFS(g,i,matrix);
        for (int i = 0; i < numVertices; i++)
            for(int j=0;j<numVertices;j++)
                if(!matrix[i][j])
                    return false;
        return true;
    }

    bool Algorithms::isContainsCycle(Graph g) {
        // Implement the isContainsCycle algorithm here
        // You can use Depth-First Search (DFS) to detect cycles in the graph
        // Return true if the graph contains a cycle, otherwise false
        return false; // Placeholder
    }

    std::string Algorithms::shortestPath(Graph g, int des, int src) {
        // Implement the shortestPath algorithm here
        // You can use Breadth-First Search (BFS) to find the shortest path from source to destination
        // Return the shortest path as a string, or an empty string if no path exists
        return ""; // Placeholder
    }

    std::string Algorithms::isBipartite(Graph g) {
        // Implement the isBipartite algorithm here
        // You can use Breadth-First Search (BFS) or Depth-First Search (DFS) to check if the graph is bipartite
        // Return "Yes" if the graph is bipartite, "No" otherwise
        return ""; // Placeholder
    }

    bool Algorithms::negativeCycle(Graph g) {
        // Implement the isContainsCycle algorithm here
        // You can use Depth-First Search (DFS) to detect cycles in the graph
        // Return true if the graph contains a cycle, otherwise false
        return false; // Placeholder
    }

}
