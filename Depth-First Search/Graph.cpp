#include <iostream>
#include <vector>
using namespace std;

class Graph{
    private:

        int numVerticies;
        vector<vector<int> > graph;

    public:

        Graph(){}

        /*
        Adds numVerticies vectors to the graph vector.
        Each vector row has numVerticies int elements
        */
        Graph(int _numVerticies){
            numVerticies = _numVerticies;

            for(int i = 0; i < numVerticies; i++){
                vector<int> row(numVerticies, 0);
                graph.push_back(row);
            }
        }

        /*
        Graph Manipulation
        */
        
        void insertEdge(int vertex1, int vertex2){
            vertex1--;
            vertex2--;

            if((vertex1 < 0 || vertex1 > numVerticies-1) ||
                (vertex2 < 0 || vertex2 > numVerticies-1)){
                    cout << "Vertex not in graph" << endl;
                    return;
            }

            graph[vertex1][vertex2] = 1;
            graph[vertex2][vertex1] = 1;
        }

        /*
        Output
        */
        void print(){
            cout << endl;
            for(int row = 0; row < numVerticies; row++){
                cout << row+1 << ": ";
                for(int col = 0; col < numVerticies; col++){
                    cout << graph[row][col] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

};