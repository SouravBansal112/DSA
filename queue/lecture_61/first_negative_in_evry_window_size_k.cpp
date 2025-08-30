#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.*/

vector<int> neg(int arr[], int k)
{

    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (dq.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(arr[dq.front()]);
    }
    for (int i = k; i < arr.size(); i++)
    {
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (dq.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}
