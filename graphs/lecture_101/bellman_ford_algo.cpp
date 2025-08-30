#include<bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1,INT_MAX);
    dist[src]=0;
    for(int i=0 ; i<n-1 ; i++){
        bool detect=false;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
                dist[v]= dist[u] + w;
                detect=true;
            }
        }
        if(detect!=true){
            break;
        }
    }
    return dist;
}





