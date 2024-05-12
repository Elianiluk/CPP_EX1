## README File for System Programming Assignment 1

### Personal Details
- **ID:** 214787483
- **Name:** Elian Iluk
- **Email:** elian10119@gmail.com

### Assignment Overview
This assignment for System Programming 2 includes the implementation of two main classes: `Graph` and `Algorithms`. Each class plays a crucial role in managing and operating on graph structures. Below is a detailed explanation of each class and their functionalities.

#### Class `Graph`

##### Fields:
1. **numOfVertices**: Represents the number of vertices in the graph. This is calculated by the size of the adjacency matrix (i.e., a 5x5 matrix implies 5 vertices). The class also checks if the graph is square (rectangular matrices are rejected with an error).

2. **numOfEdges**: Calculated by iterating through the adjacency matrix and counting non-zero entries, which represent an edge from vertex i to vertex j.

3. **adjMatrix (vec)**: A matrix of adjacency that represents the graph, provided by the user.

##### Functions:
- **loadGraph**: Accepts an adjacency matrix that represents the graph and assigns it to the `vec` field. It also counts the number of edges in the graph and updates `numOfEdges` accordingly.

- **printGraph**: Prints the number of vertices and edges in the graph.

#### Class `Algorithms`

##### Main Functions:
- **isConnected**: Determines if the graph is strongly connected, i.e., if there is a path from any vertex to every other vertex. It returns TRUE if the graph is connected; otherwise, it returns FALSE. This function uses helper functions `isPath` and `isPathHelp` to recursively check if there is a path between every pair of vertices.

- **isContainsCycle**: Iterates over each vertex and attempts to find a cycle starting from each. It uses a boolean array to mark visited vertices during traversal. If it revisits a vertex, a cycle is detected, backtracked, printed, and returns TRUE. If no cycle is found after checking all vertices, it returns FALSE.

- **shortestPath**: Calculates and prints the shortest (or least weighted) path from a source vertex to a destination vertex using the Bellman-Ford algorithm. It initializes a distance array with maximum integers, relaxes edges repeatedly, and checks for negative weight cycles that only affect the path from the source vertex to the destination vertex(if a graph has negative cycle that affect the shortest path from one vertex to another we will receive error). If a path exists, it backtracks from the destination to the source to reconstruct the path and returns it.

- **isBipartite**: Checks if the graph is bipartite by trying to color the graph using two colors. It starts from the first vertex and uses BFS to assign colors to vertices. If it successfully colors the graph without conflicts, it returns the two groups; otherwise, it returns FALSE.

- **negativeCycle**: Detects if there is a negative weight cycle in the graph using the Bellman-Ford algorithm similar to `shortestPath`. It attempts an additional relaxation after the main loop; if any relaxation is successful, it indicates a negative weight cycle.
