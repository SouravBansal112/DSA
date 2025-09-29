#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;


void solve(){
    int n,k; 
    cin >> n>>k;
    map<int,vi> adj;
    vi vis(n+1,0);
    for(int i=0; i<k; i++) {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    priority_queue<int,vi,greater<int>> pq;
    pq.push(1);
    while(!pq.empty()){
        int t=pq.top();
        vis[t]=1;
        pq.pop();
        cout<<t<<" ";
        for(int i:adj[t]) if(!vis[i]){ pq.push(i); vis[i]=1;}
    }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}