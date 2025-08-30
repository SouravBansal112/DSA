#include<iostream>
#include<stack>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &v,int n){
    stack<pair<int,int>> s;
    s.push({-1,n});
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        int element=v[i];
        while(element <= s.top().first){
            s.pop();
        }
        ans[i]=s.top().second;
        s.push({element,i});
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &v,int n){
    stack<pair<int,int>> s;
    s.push({-1,-1});
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int element=v[i];
        while(element <= s.top().first){
            s.pop();
        }
        ans[i]=s.top().second;
        s.push({element,i});
    }
    return ans;
}

int LargestRectangleArea(vector<int> heights){
    int n=heights.size();
    vector<int> next= nextSmallerElement(heights,n);
    vector<int> prev= prevSmallerElement(heights,n);
    int area=0;
    for(int i=0;i<n;i++){
        int new_area=heights[i]*(next[i]-prev[i]-1);
        area=max(new_area,area);
    }    
    return area;
}

void inVec(vector<int> &v, int n){
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
}

void outVec(vector<int> v){
    for(auto it:v){
        cout<<it;
    } 
}

int main(){ 
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    int ans = LargestRectangleArea(v);
    cout<<ans;
    
}