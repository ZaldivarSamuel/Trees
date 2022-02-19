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
};

/*
Inserts an element from an array into the new tree
*/
Node* insertNode(Node* root, queue<Node*>* q, int val){

    //Create the node with the value
    Node* newNode = new Node(val);

    //If tree is empty. This becomes the root node
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

/*
Creates a tree given an array in level order.

Initializes a root node.
For every element in the array call insertNode()
*/
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

void printPreOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->val << " ";
    printPreOrder(root->leftChild);
    printPreOrder(root->rightChild);
}

void preOrder(Node* root){
    cout << "Pre Order: ";
    printPreOrder(root);
    cout << endl;
}

void printPostOrder(Node* root){
    if(root == NULL){
        return;
    }

    printPostOrder(root->leftChild);
    printPostOrder(root->rightChild);

    cout << root->val << " ";
}

void postOrder(Node* root){
    cout << "Post Order: ";
    printPostOrder(root);
    cout << endl;
}

int main(){
    
    int arr[] = {10,20,30,40,50,60};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    Node* root = createTree(arr, arrSize);

    levelOrder(root);
    inOrder(root);
    preOrder(root);
    postOrder(root);
}