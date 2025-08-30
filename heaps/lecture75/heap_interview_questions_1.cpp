#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void push(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (2 * i <= size)
        { // while there is at least a left child
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest])
            {
                largest = left;
            }
            if (right <= size && arr[right] > arr[largest])
            {
                largest = right;
            }

            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }
};

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int> p;
    for(int i=0 ; i<k ; i++){
        p.push(arr[i]);
    }
    for(int i = k ; i<arr.size() ; i++){
        if(arr[i] < p.top()){
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
}

//You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

bool isCBT(Node* tree, int i, int tot){
    if(tree == NULL){
        return true;
    }
    if(i >= tot){  // Use >= instead of > for safety
        return false;
    }
    bool left = isCBT(tree->left, i*2 + 1, tot);
    bool right = isCBT(tree->right, i*2 + 2, tot);
    return (left && right);
}

int cnt(Node* tree){
    if(tree == NULL){
        return 0;
    }
    return 1 + cnt(tree->left) + cnt(tree->right);
}

bool maxOrder(Node* root){
    // Leaf node
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    // Only left child
    else if(root->right == NULL){
        return (root->data >= root->left->data) && maxOrder(root->left);
    }
    // Two children
    else {
        bool left = maxOrder(root->left);
        bool right = maxOrder(root->right);
        return (root->data >= root->left->data) &&
            (root->data >= root->right->data) &&
            left && right;
    }
}

bool isHeap(Node* tree) {
    int count = cnt(tree);
    return isCBT(tree, 0, count) && maxOrder(tree);
}

//Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

  void heapify(vector<int> &arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child exists and is greater than current largest
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check if right child exists and is greater than current largest
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If the largest is not the current node
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest); // Recursively heapify the affected subtree
    }
}
  
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // your code here
    vector<int> c;
    for(int i = 0 ; i< n; i++ ){
        c.push_back(a[i]);
    }
    for(int i = 0 ; i< m; i++ ){
        c.push_back(b[i]);
    }
    
    int size= c.size();
    for(int i=n/2-1 ; i>=0 ; i--){
        heapify(c,size,i);
    }
    return c;
    
}

/*Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths.*/

int minCost(vector<int>& arr) {
    
    priority_queue<int, vector<int> , greater<int> > p;
    
    int size = arr.size();
    for(int i=0 ;i<size ; i++){
        p.push(arr[i]);
    }
    int cost=0;
    while(p.size()>1){
        int a=p.top();
        p.pop();
        int b=p.top();
        p.pop();
        cost=cost+a+b;
        p.push(a+b);
    }
    return cost;
}

/*Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied to all the nodes, in the resultant converted Min Heap. */

void inorderTraversal(Node* root, vector<int>& inorderArr) {
    if (root == nullptr) {
        return;
    }
  
    // Traverse the left subtree Store the current 
    // node value Traverse the right subtree
    inorderTraversal(root->left, inorderArr);  
    inorderArr.push_back(root->data);          
    inorderTraversal(root->right, inorderArr); 
}

void preorderFill(Node* root, vector<int>& inorderArr, int& index) {
    if (root == nullptr) {
        return;
    }

    // Copy the next element from the inorder array
    root->data = inorderArr[index++];

    // Fill left and right subtree
    preorderFill(root->left, inorderArr, index);  
    preorderFill(root->right, inorderArr, index);
}

void convertBSTtoMinHeap(Node* root) {
  
    vector<int> inorderArr;

    // Step 1: Perform inorder traversal 
    // to store values in sorted order
    inorderTraversal(root, inorderArr);

    int index = 0;

    // Step 2: Perform preorder traversal and 
    // fill nodes with inorder values
    preorderFill(root, inorderArr, index);
}

