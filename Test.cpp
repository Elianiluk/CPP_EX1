#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

/*id-214787483
   name- elian iluk
   email- elian10119@gmail.com
*/

using namespace std;
using ariel::Algorithms;
using ariel::Graph;
TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); 
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph6 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, -1},
        {0, 0, 0, -1, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph3= {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph5= {
        {0, 1, 1 ,0 ,0},
        {1, 0, 1 ,0 ,0},
        {1, 1, 0 ,0 ,0},
        {0 ,0 ,0 ,0 ,-1},
        {0 ,0 ,0 ,-10 ,0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph4= {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph4 = 
        {{0,3,0,0,0,0},
         {0,0,2,0,0,0},
         {-8,0,0,0,0,0},
         {0,0,0,0,4,0},
         {0,0,0,0,0,5},
         {0,0,0,0,0,0}};
    g.loadGraph(graph4); // Load the graph to the object.
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "-1");

    vector<vector<int>> graph3= {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); 
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph3= {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph9= {
        {0, 1, 1 ,0 ,0},
        {1, 0, 1 ,0 ,0},
        {1, 1, 0 ,0 ,0},
        {0 ,0 ,0 ,0 ,-1},
        {0 ,0 ,0 ,-10 ,0}};
    g.loadGraph(graph9);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph4= {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph5= {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph6= {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph8= {
        {0, 1, 1 ,0},
        {1, 0, 1 ,0},
        {1, 1, 0 ,0},
        {0 ,0 ,0 ,0}};
    g.loadGraph(graph8);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph7= {
        {0, 1, 1 ,0},
        {1, 0, 1 ,0},
        {1, 1, 0 ,0},
        {0 ,0 ,-10 ,0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph4= {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2}, B={}");

    vector<vector<int>> graph5= {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test negative cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle detected.");

    vector<vector<int>> graph1 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, -30, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative cycle detected.");

    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g)== "No negative cycle detected.");

    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {-10, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g)== "Negative cycle detected.");

    vector<vector<int>> graph3= {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g)== "No negative cycle detected.");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> graph1= {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    CHECK_THROWS(g.loadGraph(graph1));
}

