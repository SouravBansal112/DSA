#include<bits/stdc++.h>
using namespace std;

void solve(int node,int parent,int cat,int &ans, vector<vector<int>> &adj,vector<int> &c,int &m){
    if(c[node]==0){
        cat=0;
    }
    else{
        cat++;
    }
    if(cat>m){
        return;
    }
    bool leaf=true;
    for(auto child:adj[node]){
        if(child!=parent){
            leaf=false;
            solve(child,node,cat,ans,adj,c,m);
        }
    }
    if(leaf){
        ans++;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> c(n);
    for(int i=0 ; i<n ; i++){
        cin>>c[i];
    }
    vector<vector<int>> adj(n);
    for(int i =0 ; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans=0;
    vector<bool> vis(n,false);
        solve(0,-1,0,ans,adj,c,m);
    cout<<ans;
    return 0;
}