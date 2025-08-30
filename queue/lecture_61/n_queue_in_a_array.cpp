#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class nqueue
{
    public:
    int k;
    int n;
    int *arr;
    int *rear;
    int *front;
    int *next;
    int freespot;

    nqueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freespot = 0;

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    void enqueue(int m, int x)
    {
        if (freespot == -1)
        {
            return;
        }
        int index = freespot;
        freespot = next[index];
        if (front[m - 1] == -1)
        {
            front[m - 1] = index;
        }
        else
        {
            next[rear[m - 1]] = index;
        }

        next[index] = -1;
        rear[m - 1] = index;
        arr[index] = x;
        cout<< "enqueued successful" << endl;
    }

    int dequeue(int m)
    {
        if (front[m - 1] == -1)
        {
            cout << "underflow/n";
            return -1;
        }
        int index = front[m - 1];
        front[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main()
{
    nqueue q(8, 2);
    q.enqueue(1, 5);
    q.enqueue(1, 3);
    q.enqueue(1, 3);
    q.enqueue(2, 4);
    q.dequeue(1);
    q.dequeue(1);
    q.dequeue(1);
    q.dequeue(1);
}