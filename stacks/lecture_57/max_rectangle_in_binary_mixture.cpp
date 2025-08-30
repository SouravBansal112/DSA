#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &v, int n)
{
    stack<pair<int, int>> s;
    s.push({-1, n});
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int element = v[i];
        while (element <= s.top().first)
        {
            s.pop();
        }
        ans[i] = s.top().second;
        s.push({element, i});
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &v, int n)
{
    stack<pair<int, int>> s;
    s.push({-1, -1});
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int element = v[i];
        while (element <= s.top().first)
        {
            s.pop();
        }
        ans[i] = s.top().second;
        s.push({element, i});
    }
    return ans;
}

int LargestRectangleArea(vector<int> heights)
{
    int n = heights.size();
    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int new_area = heights[i] * (next[i] - prev[i] - 1);
        area = max(new_area, area);
    }
    return area;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    

    vector<int> heights(m, 0);
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0 && heights[j] != 0)
            {
                heights[j] == 0;
            }
            else
            {
                heights[j] == heights[j] + mat[i][j];
            }
        }
        int new_area = LargestRectangleArea(heights);
        area = max(area, new_area);
    }
}