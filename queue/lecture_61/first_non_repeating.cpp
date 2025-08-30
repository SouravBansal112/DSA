#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string rep(vector<char> &v)
{
    int n = v.size();
    string ans;
    map<char, int> m;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        char ch = v[i];
        m[ch]++;
        q.push(ch);
        while (!q.empty())
        {
            if (m[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}