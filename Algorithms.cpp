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
        std::vector<int>::size_type n = static_cast<std::vector<int>::size_type>(g.getVertices());
        std::vector<bool> visited(n, false);
        std::vector<int> parent(n, -1);
        std::vector<std::vector<int>> cycles;

        for (unsigned long i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (hasCycleDFS(g, i, visited, parent, cycles)) {
                    // Cycle detected, print the cycle(s)
                    for (const auto& cycle : cycles) {
                        std::string result;
                        for (size_t j = 0; j < cycle.size(); ++j) {
                            if (j > 0) result += "->"; // Add arrows between nodes
                            result += std::to_string(cycle[j]);
                        }
                        std::cout << result;
                        std::cout << ",";
                        return true; // Return the first found cycle
                    }
                }
            }
        }
        // No cycle found
        return false;
    } 

    bool Algorithms::hasCycleDFS(Graph graph, unsigned long node, std::vector<bool>& visited, std::vector<int>& parent, std::vector<std::vector<int>>& cycles) 
    {
        visited[node] = true;

        auto adjacencyMatrix = graph.getGraph();
        for (unsigned long i = 0; i < graph.getVertices(); ++i) {
            if (adjacencyMatrix[node][i]) {
                if (!visited[i]) {
                 parent[i] = node;
                    if (hasCycleDFS(graph, i, visited, parent, cycles)) {
                        return true;
                    }
                } else if (parent[node] != i) {
                 // Cycle detected, backtrack to find the cycle path
                    std::vector<int> cycle;
                    int cur = node;
                    while (cur != i) {
                        cycle.push_back(cur);
                        cur = parent[static_cast<std::vector<int>::size_type>(cur)];

                    }
                    cycle.push_back(i);
                    cycle.push_back(node);
                    cycles.push_back(cycle);
                    return true;
                }
            }
        }
        return false;
    }

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
        std::vector<int>::size_type n = static_cast<std::vector<int>::size_type>(g.getVertices());
        std::vector<bool> visited(n, false);
        std::vector<int> parent(n, -1);
        std::vector<std::vector<int>> cycles;
        std::vector<std::vector<int>> edges=g.getGraph();

        for (unsigned long i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (hasCycleDFS(g, i, visited, parent, cycles)) {
                    // Cycle detected, print the cycle(s)
                    int sum=0;
                    for (auto cycle : cycles) {
                        std::string result;
                        for (size_t j = 0; j < cycle.size(); ++j) {
                            if (j > 0) result += "->"; // Add arrows between nodes
                            result += std::to_string(cycle[j]);
                            if(j<cycle.size()-1)
                                sum += edges[static_cast<std::vector<std::vector<int>>::size_type>(cycle[j])][static_cast<std::vector<std::vector<int>>::size_type>(cycle[j + 1])]; // Calculate the sum of edge weights
                        }
                        if(sum<0)
                        {
                            std::cout << result;
                            std::cout << ",";
                            std::cout << "the sum is: " << sum;
                            std::cout << ",";
                            return true; // Return the first found cycle
                        }
                    }
                }
            }
        }
        // No cycle found
        std::cout << "doesnt contain a negative cycle";
        std::cout << ",";
        return false;
    }

}
