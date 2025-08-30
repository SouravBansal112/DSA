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

/*Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.*/

int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for(int i=0 ; i<arr.size() ; i++){
		int subSum=0;
		for(int j=i ; j<arr.size() ; j++){
			subSum+=arr[j];
            if (minHeap.size() < k) {
                minHeap.push(subSum);
            } else if (subSum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(subSum);
            }			
		}
	}
	return minHeap.top();
}

/*You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.*/

class node{
    public:
    int data;
    int i;
    int j;
    node(int data,int row,int col){
        this->data = data;
        i=row;
        j=col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare > p;

    for(int i=0 ; i<k ; i++){
        node* tmp= new node(kArrays[i][0],i,0);
        p.push(tmp);
    }
    vector<int> ans;
    while(p.size() > 0){
        node* tmp = p.top();
        ans.push_back(tmp->data);
        p.pop();

        int i=tmp->i;
        int j=tmp->j;

        if((tmp->j)+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            p.push(next);
        }
    }
    return ans;
}

/*Given 'k' sorted linked lists, each list is sorted in increasing order. You need to merge all these lists into one single sorted list. You need to return the head of the final linked list.*/

class Lnode
{
public:
    int data;
    Lnode *next;
    Lnode()
    {
        this->data = 0;
        next = NULL;
    }
    Lnode(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Lnode(int data, Lnode* next)
    {
        this->data = data;
        this->next = next;
    }
};

Lnode* mergeKLists(vector<Lnode*> &listArray){
    priority_queue<Lnode*, vector<Lnode*>, compare > p;
    int k=listArray.size();
    for(int i=0 ; i<k ; i++){
        p.push(listArray[i]);
    }
    Lnode*  head=NULL;
    Lnode* tail = NULL;
    while (!p.empty()) {
        Lnode* top = p.top();
        p.pop();

        if (head == NULL) {
            head = tail = top;
        } else {
            tail->next = top;
            tail = top;
        }

        if (top->next) {
            p.push(top->next);
        }
    }
    return head;
}








