#include<bits/stdc++.h>
using namespace std;

/*You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices (numbered from 0 to V-1) and E number of edges.
Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.*/
bool cmp(vector<int> &a, vector<int> &b){
    return a[2]<b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0 ; i<n ; i++){
        parent[i]= i;
        rank[i]=0;
    }
}

int findParent(int n,vector<int> &parent){
    if(parent[n]==n){
        return n;
    }
    return parent[n]=findParent(parent[n],parent);
}

void makeUnion(int u, int v, vector<int> &parent, vector<int> &rank){
    u=findParent(u,parent);
    v=findParent(v,parent);
    if(rank[u]<=rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[u]=v;
        rank[v]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    int ans=0;
    for(int i=0; i<edges.size() ; i++){
        int u=findParent(edges[i][0],parent);
        int v=findParent(edges[i][1],parent);
        int w=edges[i][2];
        if(u!=v){
            makeUnion(u,v,parent,rank);
            ans+=w;
        }
    }
    return ans; 
}





