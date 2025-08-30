#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Nstack
{

    int n;
    int s;
    int freespot = 0;
    int *arr;
    int *top;
    int *next;

public:
    Nstack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        next = new int[s];
        top = new int[n];

        for (int i = 0; i < s - 1; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
    }

    bool push(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }
        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
        return true;
    }

    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1;
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;

        return 1;
    }
};