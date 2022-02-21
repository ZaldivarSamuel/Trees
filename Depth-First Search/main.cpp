#include <iostream>
#include "Graph.cpp"
using namespace std;

void addEdges(Graph& g){
    g.insertEdge(1,3);
    g.insertEdge(1,6);
    g.insertEdge(1,7);
    
    g.insertEdge(2,5);
    g.insertEdge(2,3);

    g.insertEdge(3,5);
    g.insertEdge(3,6);

    g.insertEdge(4,5);
   // g.insertEdge(4,6);
}

int main(){
    
    Graph g(7);
    g.print();

    addEdges(g);
    
    g.print();
    g.depthFristSearch(4);
}

