#include <iostream>
#include <vector>

class Graph{
    private:
        int numOfEdges;
        std::vector<std::vector<int>> vec;
        int numOfVertices;
    public:
        Graph()
        {
            this->numOfEdges=0;
            this->numOfVertices=0;
        }  


        void loadGraph(std::vector<std::vector<int>> vec1)
        {
            if(vec1.size()!=vec1[0].size())
            {
                std::cout << "Invalid graph: The graph is not a square matrix."<<std::endl;
                exit(1);
            }

            numOfVertices=vec1.size();
            vec=vec1;
            int countEdges=0;
            for(unsigned long i=0;i<vec1.size();i++)
                for(unsigned long j=0;j<vec1.size();j++)
                {
                    countEdges++;
                }
            numOfEdges=countEdges;   
        }

        void printGraph()
        {
            std::cout << "Graph with "<< numOfVertices << "vertices and " << numOfEdges << "edges"<<std::endl;
        }

};