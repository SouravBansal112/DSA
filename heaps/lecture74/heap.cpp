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
    void insert(int val)
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

    void deleteh()
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

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // Check if left child exists and is greater than current largest
    if (left <= size && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check if right child exists and is greater than current largest
    if (right <= size && arr[right] > arr[largest])
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

void minHeapify(vector<int> &arr, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < size && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, size, smallest);  // Recursively fix the affected subtree
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int size = arr.size();
    for (int i= size/2-1 ; i>=0 ; i--){
        minHeapify(arr,size,i);
    }
    return arr;
}

void heapSort(int arr[],int n){
    int size = n;

    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}

int main()
{
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    cout<< "element at top "<< pq.top()<< endl;
    pq.pop();
    cout<< "size is" << pq.size() << endl;

    //minheap
    priority_queue<int, vector<int> , greater<int> > minheap;

    minheap.push(5);
    minheap.push(1);

    cout<< "element at top "<< pq.top()<< endl;
    pq.pop();
    cout<< "size is" << pq.size() << endl;

    return 0;
}
