/*id-214787483
   name- elian iluk
   email- elian10119@gmail.com
*/
 
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
 
using ariel::Algorithms;
using ariel::Graph;
using namespace std;
 
int main()
{
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0}};
    g.loadGraph(graph); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 3 vertices and 2 edges."
    cout << ariel::Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << ariel::Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    cout << ariel::Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << ariel::Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."
    cout << ariel::Algorithms::negativeCycle(g) << endl;


    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = 
        {{0,3,0,0,0,0},
         {0,0,2,0,0,0},
         {-8,0,0,0,0,0},
         {0,0,0,0,4,0},
         {0,0,0,0,0,5},
         {0,0,0,0,0,0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 4 edges."
    cout << ariel::Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << ariel::Algorithms::shortestPath(g, 0,1) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << ariel::Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    cout << ariel::Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).
    cout << ariel::Algorithms::negativeCycle(g) << endl;

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
            {0, 10, -1, 1, 0},
            {10, 0, 10, 0, 0},
            {-1, 10, 0, 0, 2},
            {1, 0, 0, 0, 0},
            {0, 0, 2, 0, 0}};
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 7 edges."
    cout << ariel::Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << ariel::Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->1->2->3->4.
    cout << ariel::Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << ariel::Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."
    cout << ariel::Algorithms::negativeCycle(g) << endl;


    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }
}