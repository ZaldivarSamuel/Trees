#include <iostream>
using namespace std;

struct Node{

    Node* leftChild;
    Node* rightChild;

    int val;

    Node(int _val){
        val = _val;

        leftChild = NULL;
        rightChild = NULL;
    }
};


int main(){
    
    int arr[] = {10,20,30,40,50,60};

}