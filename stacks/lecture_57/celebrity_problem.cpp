#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
        s.push(i);
    }

    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (v[a][b] == 1)
        {
            s.push(b);
        }
        if (v[b][a] == 1)
        {
            s.push(a);
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (v[s.top()][j] == 1)
        {
            return -1;
        }
        if (v[j][s.top()] == 0 && j != s.top())
        {
            return -1;
        }
    }

    int ans = s.top();
    cout << ans;

    return ans;
}