#include <iostream>
#include "Graph.cpp"
using namespace std;

int main(){
    
    Graph g(7);
    g.print();

    g.insertEdge(1,3);


    g.print();
}

