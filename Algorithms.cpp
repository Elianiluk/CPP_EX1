#include "Algorithms.hpp"
#include <queue>
#include <vector>
#include <iostream>

namespace ariel {


    bool Algorithms::isPathHelp(const std::vector<std::vector<int>> edges, unsigned long src, int des, std::vector<bool> visited) {
        if (src == des) {
            return true;
        }
        visited[src] = true;
        for (unsigned long i = 0; i < edges.size(); i++) {
            if (edges[src][i] && !visited[i]) {
                if (isPathHelp(edges, i, des, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool Algorithms::isPath(const std::vector<std::vector<int>> edges, unsigned long src, int des) {
        std::vector<bool> visited(edges.size(), false);
        return isPathHelp(edges, src, des, visited);
    }

    int Algorithms::isConnected(Graph g) {
        int numVertices = g.getVertices();
        std::vector<std::vector<int>> edges = g.getGraph();
        for (unsigned long i = 0; i < numVertices; i++) {
            for (unsigned long j = 0; j < numVertices; j++) {
                if (!isPath(edges, i, j)) {
                    return 0;
                }
            }
        }
        return 1;
    }

     bool Algorithms::isContainsCycle(Graph g) {
        // int v=g.getVertices();
        // std::vector<bool> visited(static_cast<std::vector<bool>::size_type>(v), false);
        // std::vector<bool> recStack(static_cast<std::vector<bool>::size_type>(v), false);


        // for (unsigned long i=0;i<v;i++) {
        //     if (isContainsCycleUtil(g, i, visited, recStack)) {
        //         std::cout << "Graph contains a cycle." << std::endl;
        //         return true;
        //     }
        // }

        // std::cout << "Graph does not contain a cycle." << std::endl;
        return false;
    }

    //  bool Algorithms::isContainsCycleUtil(Graph g, unsigned long v, std::vector<bool>& visited, std::vector<bool>& recStack) {
    //     if (!visited[v]) {
    //         visited[v] = true;
    //         recStack[v] = true;

    //         std::vector<std::vector<int>> adj = g.getGraph();
    //         for (unsigned long i = 0; i < g.getVertices(); ++i) {
    //             if (adj[v][i] && !visited[i] && isContainsCycleUtil(g, i, visited, recStack)) {
    //                 return true;
    //             } else if (recStack[i]) {
    //                 // Cycle found, print it
    //                 printCycle(g, v, i);
    //                 return true;
    //             }
    //         }
    //     }
    //     recStack[v] = false; // Remove the vertex from recursion stack
    //     return false;
    // }

    //  void Algorithms::printCycle(Graph g, unsigned long start,int end) {
    //     std::vector<std::vector<int>> adj = g.getGraph();
    //     std::vector<int> path;
    //     path.push_back(end);
    //     while (start != end) {
    //         path.push_back(start);
    //         end = start;
    //         for (unsigned long i = 0; i < g.getVertices(); ++i) {
    //             if (adj[start][i] && i != start) {
    //                 start = i;
    //                 break;
    //             }
    //         }
    //     }
    //     for (unsigned long i = path.size()-1; i >= 0; --i)
    //         std::cout << path[i] << "->";
        
    // }

    std::string Algorithms::shortestPath(Graph g, int src,int des) {
        std::vector<int>::size_type numVertices = static_cast<std::vector<int>::size_type>(g.getVertices());
        // std::vector<int> dist(numVertices, 1000);
        int v= g.getVertices();
        int dist[v];
        for(int i=0;i<v;i++)
            dist[i]=1000;
        dist[src] = 0;

        std::vector<std::vector<int>> edges = g.getGraph();

        // Relax all edges V-1 times
        for (unsigned long i = 0; i < g.getVertices() - 1; ++i) {
            for (unsigned long u = 0; u < g.getVertices(); ++u) {
                for (unsigned long v = 0; v < g.getVertices(); ++v) {
                    if (edges[u][v] != 0 && dist[u] != 1000 && dist[u] + edges[u][v] < dist[v]) {
                        dist[v] = dist[u] + edges[u][v];
                    }
                }
            }
        }

        // Check for negative cycles
        for (unsigned long u = 0; u < g.getVertices(); ++u) {
            for (unsigned long v = 0; v < g.getVertices(); ++v) {
                if (edges[u][v] != 0 && dist[u] != 1000 && dist[u] + edges[u][v] < dist[v]) {
                    return "Negative cycle detected.";
                }
            }
        }
        
        if(dist[des]>=1000)
            std::cout << "-1";
        else
            std::cout << dist[des];    

        // Construct the shortest path string
        // int current = des;
        // std::vector<int> path;
        // while (current != src) {
        //     path.push_back(current);
        //     for (unsigned long v = 0; v < g.getVertices(); ++v) {
        //         if (edges[v][current] != 0 && dist[current] == dist[v] + edges[v][current]) {
        //             current = v;
        //             break;
        //         }
        //     }
        // }
        // path.push_back(src);
        // for (unsigned long i = path.size() - 1; i >= 0; --i) {
        //     std::cout << path[i]; 
        //     if (i != 0) std::cout << "->";
        // }
        return "";
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
