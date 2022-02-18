#include <iostream>
#include <queue>

using namespace std;

struct Node{

    Node* leftChild;
    Node* rightChild;

    int val;

    Node(){
        val = 0;
        leftChild = NULL;
        rightChild = NULL;
    }

    Node(int _val){
        val = _val;

        leftChild = NULL;
        rightChild = NULL;
    }

    Node(int _val, Node* _leftChild, Node* _rightChild){
        val = _val;
        leftChild = _leftChild;
        rightChild = _rightChild;
    }
};

Node* insertNode(Node* root, queue<Node*>* q, int val){

    Node* newNode = new Node(val);

    if(root == NULL){
        root = newNode;
    }
    else if(q->front()->leftChild == NULL){
        q->front()->leftChild = newNode;
    }
    else{
        q->front()->rightChild = newNode;
        q->pop();
    }

    q->push(newNode);
    
    return root;
}

Node* createTree(int arr[]){

    Node* root = NULL;
    queue<Node*>* q = new queue<Node*>();

    int arrSize = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < arrSize; i++){
        root = insertNode(root, q, arr[i]);
    }

    return root;
}

int main(){
    
    int arr[] = {10,20,30,40,50,60};
    Node* root = createTree(arr);
}