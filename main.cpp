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

Node* createTree(int arr[], int arrSize){

    Node* root = NULL;
    queue<Node*>* q = new queue<Node*>();

    for(int i = 0; i < arrSize; i++){
        root = insertNode(root, q, arr[i]);
    }

    return root;
}

/*
Also known as Breadth-First
*/
void levelOrder(Node* tree){
    queue<Node*> q;

    q.push(tree);
    cout << "Level Order: ";
    while(!q.empty()){
        Node* currentNode = q.front();

        cout << currentNode->val << " ";
        q.pop();

        if(currentNode->leftChild != NULL){
            q.push(currentNode->leftChild);
        }

        if(currentNode->rightChild != NULL){
            q.push(currentNode->rightChild);
        }
    }
    cout << endl;
}

void printInOrder(Node* root){
    if(root == NULL){
        return;
    }

    printInOrder(root->leftChild);
    cout << root->val << " ";
    printInOrder(root->rightChild);
}

void inOrder(Node* root){
    cout << "InOrder: ";
    printInOrder(root);
    cout << endl;
}

int main(){
    
    int arr[] = {10,20,30,40,50,60};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    Node* root = createTree(arr, arrSize);

    levelOrder(root);
    inOrder(root);
}