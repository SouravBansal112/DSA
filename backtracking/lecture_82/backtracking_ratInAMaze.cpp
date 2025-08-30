#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n, vector<vector<int>> &arr, vector<vector<bool>> &visited) {
    return (i >= 0 && j >= 0 && i < n && j < n && !visited[i][j] && arr[i][j] == 1);
}

void solve(int i,int j,int &n,vector < vector < int >> & arr,vector<vector<bool>> &visited,vector<string> &ans,string &path){
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return;
    }
    if(isSafe(i+1,j,n,arr,visited)){
        visited[i+1][j]=1;
        path.push_back('D');
        solve(i+1,j,n,arr,visited,ans,path);
        path.pop_back();
        visited[i+1][j]=0;
    }
    if(isSafe(i,j-1,n,arr,visited)){
        visited[i][j-1]=1;
        path.push_back('L');
        solve(i,j-1,n,arr,visited,ans,path);
        path.pop_back();
        visited[i][j-1]=0;
    }
    if(isSafe(i,j+1,n,arr,visited)){
        visited[i][j+1]=1;
        path.push_back('R');
        solve(i,j+1,n,arr,visited,ans,path);
        path.pop_back();
        visited[i][j+1]=0;
    }
    if(isSafe(i-1,j,n,arr,visited)){
        visited[i-1][j]=1;
        path.push_back('U');
        solve(i-1,j,n,arr,visited,ans,path);
        path.pop_back();
        visited[i-1][j]=0;
    }
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {

    vector<vector<bool>> visited(n,vector<bool>(n,0));
    vector<string> ans;
    if(arr[0][0]==0){return ans;}
    visited[0][0]=1;
    string path="";
    solve(0,0,n,arr,visited,ans,path);
    return ans;
}















