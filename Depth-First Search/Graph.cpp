#include <iostream>
#include <vector>
#include <stack>
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
        Searching
        */
        bool depthFristSearch(int target){

            stack<int> toVisit;
            vector<int> visited(numVerticies, 0);

            //Start with vector 1
            toVisit.push(1);
            visited[0] = 1;

            while(!toVisit.empty()){
                int vertex = toVisit.top();

                if(vertex == target){
                    return true;
                }
                vertex--; 
                toVisit.pop();

                for(int i = 0; i < graph[vertex].size(); i++){
                    if(graph[vertex][i] == 1 && visited[i] != 1){
                        toVisit.push(i+1);
                        visited[i] = 1;
                    }
                }
            }   

            return false;
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