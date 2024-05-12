#include "Algorithms.hpp"
#include <queue>
#include <vector>
#include <iostream>
#include <limits>

/*id-214787483
   name- elian iluk
   email- elian10119@gmail.com
*/

namespace ariel { 

    /*a function that trying to detect if there is a pth from src to des recursivly
      we start at src and we are walking over the graph trying to get to the des,
      each time going step by step through the vertices, return TRUE if there is a path
      return FALSE if there is no path from src to des*/
    bool Algorithms::isPathHelp(const std::vector<std::vector<int>> edges, unsigned long src, int des, std::vector<bool> visited) {
        if (src == des) {//if we manage to get to des, it means there is a path and return TRUE
            return true;
        }
        visited[src] = true;//mark the vertice we are on him now as true because we can get to him from the original src
        for (unsigned long i = 0; i < edges.size(); i++) {
            if (edges[src][i]!=0 && !visited[i]) {//going through the vertices we can get from src and trying to get to des
                if(isPathHelp(edges, i, des, visited)) {//trying to find a path from i to des because we can get to i from src
                    return true;
                }
            }
        }
        return false;
    }

    /*help function that add an array to detect to which vertices we can get from src
      and send it to another help function "isPathHelp"*/
    bool Algorithms::isPath(const std::vector<std::vector<int>> edges, unsigned long src, int des) {
        std::vector<bool> visited(edges.size(), false);
        return isPathHelp(edges, src, des, visited);
    }

    /**
     * function to check if graph is strongly connected, to know that
      we going through all the vertces and trying to understand if there is 
      a path from each vertice to any other vertice, if yes return 1
      if there is a vertice which we cant get to from other vertice return 0
      @param Graph g- graph
      @return true if the graph is connected, false if not connected
      */
    int Algorithms::isConnected(Graph g) {
        int numVertices = g.getVertices();
        std::vector<std::vector<int>> edges = g.getGraph();
        for (unsigned long i = 0; i < numVertices; i++) {
            for (unsigned long j = 0; j < numVertices; j++) {
                if (!isPath(edges, i, j)) {//calling a function that detects if there is a path from i to j
                    return 0;
                }
            }
        }
        return 1;
    }

    //funtion to detect and print if there is a cycle in the graph
     bool Algorithms::isContainsCycle(Graph g) {
        std::vector<int>::size_type n = static_cast<std::vector<int>::size_type>(g.getVertices());
        std::vector<bool> visited(n, false);
        std::vector<int> parent(n, -1);
        std::vector<std::vector<int>> cycles;

        for (unsigned long i = 0; i < n; ++i) {//try to find a cycle from each vertice
            if (!visited[i]) {
                if (hasCycleIndex(g, i, visited, parent, cycles)) {//run DFS and try to find a cycle from each vertice
                    // cycle detected, print it
                    for (std::vector<int> cycle : cycles) {
                        if(cycle.size()<=2)//a cycle must have at least 3 vertices
                            continue;
                        for (size_t j = 0; j < cycle.size(); ++j) {
                            if (j > 0) 
                                std::cout << "->";
                            std::cout << std::to_string(cycle[j]);
                        }
                         std::cout << ",";
                        return true; // return that there is a cycle in the graph
                    }
                }
            }
        }
        // no cycle found
        return false;
    } 

    //function that run DFS from a vertice and try to find a cycle
    bool Algorithms::hasCycleIndex(Graph graph, unsigned long node, std::vector<bool>& visited, std::vector<int>& parent, std::vector<std::vector<int>>& cycles) {
        visited[node] = true;
        for (unsigned long i = 0; i < graph.getVertices(); i++) {
            if (graph.getGraph()[node][i] != 0) { 
                if (!visited[i]) {
                    parent[i] = node;
                    if (hasCycleIndex(graph, i, visited, parent, cycles)) {
                        return true;
                    }
                } else if (parent[node] != i) {// if yesy so it means a cycle detected
                    std::vector<int> cycle;
                    int cur = node;
                    while (cur != i) {
                        cycle.push_back(cur);
                        cur = parent[static_cast<std::vector<int>::size_type>(cur)];
                        if (cur == -1) break;
                    }
                    if (cur != -1) { // If cur is -1, it means it's not a valid cycle due to negative edges
                        cycle.push_back(i);
                        cycle.push_back(node);
                        cycles.push_back(cycle);
                        return true;
                    }
                }
            }
        }
        return false;
    }


    /*function to detect the shortest path from src to des using bellman ford
      (because the graph can have negative weights), return the shortest path from src to des is exist
      return -1 if there is no path from src to des*/
    std::string Algorithms::shortestPath(Graph g, int src,int des) {
        int v= g.getVertices();
        int dist[v];//an array that comsume the shortest path from src to any other vertice
        for(int i=0;i<v;i++)
            dist[i]=std::numeric_limits<int>::max();//intiallize the shortest path from src to any other vertice to infinity
        dist[src] = 0;//there is no edge from src to itself

        std::vector<std::vector<int>> edges = g.getGraph();
        std::vector<int> parent(static_cast<unsigned long>(v), -1);

        // relax all edges V-1 times, bellman ford algorithm
        for (unsigned long i = 0; i < g.getVertices() - 1; i++) {
            for (unsigned long u = 0; u < g.getVertices(); u++) {
                for (unsigned long v = 0; v < g.getVertices(); v++) {
                    if (edges[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + edges[u][v] < dist[v]) {
                        dist[v] = dist[u] + edges[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        // check for negative cycles
        // for (unsigned long u = 0; u < g.getVertices(); ++u) {
        //     for (unsigned long v = 0; v < g.getVertices(); ++v) {
        //         if (edges[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + edges[u][v] < dist[v]) {
        //             return "-1";//negative cycle
        //         }
        //     }
        // }   

        //construct the shortest path string from src to des
        if(dist[des]==std::numeric_limits<int>::max())
            return "-1";

        std::vector<int> path;
        // for (int i = des; i != -1 || i==src; i = parent[static_cast<unsigned long>(i)]) 
        //     path.push_back(i);
        int i=des;
        while(i!=-1 && i!=src)
        {
            path.push_back(i);
            i=parent[static_cast<unsigned long>(i)];
        }
        path.push_back(src);

        if (path.empty()) 
            return "-1";

        //check if the path contains a negative cycle
        unsigned long last = path.size();
        for (unsigned long i = last-1; i <= 0; ++i) {
            unsigned long u = static_cast<unsigned long>(path[i]);
            unsigned long v = static_cast<unsigned long>(path[(i + 1)]);
            if (dist[u] + edges[u][v] < dist[v]) {                 
                return "Negative cycle affects the path";
            }
        }
        
        std::string sh;
        for (int i = path.size() - 1; i >= 0; i--) {
            sh+=std::to_string(path[static_cast<std::vector<int>::size_type>(i)]);
            if(i!=0)
                sh+="->";
        }
        return sh;
        //return "The shortest path is: "+std::to_string(dist[des]);//return the shortest path from src to des
        // unsigned long current = static_cast<unsigned long>(des);
        // std::vector<int> path(static_cast<std::vector<int>::size_type>(g.getVertices()), -1);
        // unsigned long count=0;
        // while (current != src) {
        //     path[count]=current;
        //     //std::cout <<current;
        //     for (unsigned long v = 0; v < g.getVertices(); ++v) {
        //         if (edges[v][current] != 0 && dist[current] == dist[v] + edges[v][current]) {
        //             current = v;
        //             break;
        //         }
        //     }
        //     count++;
        // }
        // path[count]=src;
        // std::string sh;
        // while(count!=0)
        // {
        //     sh+=std::to_string(path[count--])+"->";
        //     //count--;
        // }
        // sh+=std::to_string(path[count]);  
        // return sh; //return the shortest path
    }

    /*in this function we check if a graph is bipartite, to detect this
      we try to colour the grph using 2 colour exactly, if it can be done
      it mean that we can divide the vertices into 2 groups independently and we will return YES,
      if we cant, it means we cant divide the vertices and we will return NO*/

    std::string Algorithms::isBipartite(Graph g) {
        int numVertices = g.getVertices();
        std::vector<int> colors(static_cast<size_t>(numVertices), std::numeric_limits<int>::max()); // initialize colors for each vertex
        std::queue<int> q;

        std::vector<int> group1(static_cast<size_t>(numVertices), -1), group2(static_cast<size_t>(numVertices), -1); // to store the two groups
        unsigned long count1=0,count3=0,count2=0;
        // start BFS from each uncolored vertex
        for (unsigned long i = 0; i < numVertices; ++i) {
            if (colors[i] == std::numeric_limits<int>::max()) {
                q.push(i);
                colors[i] = 1; // assign color 0 to the source vertex
                group1[count1]=i; // add to group 1
                count1++;

                while (!q.empty()) {
                    unsigned long u = static_cast<size_t>(q.front());
                    q.pop();

                // search the neighbors and action according to its color
                    for (unsigned long v = 0; v < numVertices; ++v) {
                        if (g.getGraph()[u][v] != 0) { // if v and u are neighbors
                            if (colors[v] == std::numeric_limits<int>::max()) { // if v is not colored
                                if(colors[u]==1)// assign the opposite color of u to v
                                    colors[v]=2;
                                else
                                    colors[v]=1;
                                q.push(v);

                                if (colors[v] == 1) {
                                    group1[count1]=v; // add to group 1
                                    count1++;
                                } else {
                                    group2[count2]=v; // add to group 2
                                    count2++;
                                }
                            } else if (colors[v] == colors[u]) { // if v has the same color as u it means thr graph isnt bipartite
                                return "0";
                            }
                        }
                    }
                }
            }
        }
        
        // if the graph is bipartite, build a result string showing the two groups
        std::string result = "The graph is bipartite: A={";
        int count5=group1.size();
        for (int vertex : group1) {
            if(vertex==-1)
                break;
            if(count5!=1)
                result += std::to_string(vertex) + ", ";
            else
                result += std::to_string(vertex);
            count5--;  
        }

        if(result[result.size()-1]==',' || result[result.size()-1]==' '){
            result.pop_back();
        }
        if(result[result.size()-1]==',' || result[result.size()-1]==' '){
            result.pop_back();
        }

        result += "}, B={";
        int count4=group2.size();
        for (int vertex : group2) {
            if(vertex==-1)
                break;
            if(count4!=1)
                result += std::to_string(vertex) + ", ";
            else
                result += std::to_string(vertex);
            count4--; 
        }

        if(result[result.size()-1]==',' || result[result.size()-1]==' '){
            result.pop_back();
        }
        if(result[result.size()-1]==',' || result[result.size()-1]==' '){
            result.pop_back();
        }
        result += "}";
        
        return result;//return the divide into 2 independents groups
    }
 
    std::string Algorithms::negativeCycle(Graph g) {
        int numVertices = g.getVertices();
        std::vector<std::vector<int>> edges = g.getGraph();

        // initialize distance vector outside the initial for-loop since we are reinitializing for every start vertex
        std::vector<int> dist(static_cast<std::vector<int>::size_type>(numVertices), std::numeric_limits<int>::max());

        // run Bellman-Ford from each vertex
        for (unsigned long src = 0; src < numVertices; ++src) {
            // initialize distances from source to all other vertices
            for(unsigned long i=0;i<numVertices;i++)
                dist[i]=std::numeric_limits<int>::max();
            dist[src] = 0;

            // relax all edges V-1 times
            for (unsigned long i = 0; i < numVertices; i++) {
                for (unsigned long u = 0; u < numVertices; u++) {
                    for (unsigned long v = 0; v < numVertices; v++) {
                        if (edges[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + edges[u][v] < dist[v]) {
                            dist[v] = dist[u] + edges[u][v];
                        }
                    }
                }
            }

        // check for negative cycles
        for (unsigned long u = 0; u < numVertices; u++) {
            for (unsigned long v = 0; v < numVertices; v++) {
                if (edges[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + edges[u][v] < dist[v]) {
                    return "Negative cycle detected.";
                }
            }
        }
    }
    return "No negative cycle detected.";
    }

}
