#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void createAdj(int n, map<int,vector<int>> &adj,map<int,int> &cnt){
    for(int i=0; i<n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }
}

void dfs(int i, map<int,vector<int>> &adj, vector<bool> &vis,set<int> &a, set<int> &b, bool flag){
    if(flag) a.insert(i);
    else b.insert(i);
    vis[i]=true;
    for(auto j:adj[i]){
        if(!vis[j]){
            dfs(j,adj,vis,a,b,!flag);
        }
    }
}

void solve(){
    int n; 
    cin >> n;
    set<int> a;
    set<int> b;
    map<int,vector<int>> adj;
    map<int,int> cnt;
    createAdj(n-1,adj,cnt);
    vector<bool> vis(n+1,false);
    bool flag=true;
    dfs(1,adj,vis,a,b,flag);
    ll ans=0;
    ll x= b.size();
    for(auto i:a){
      if(cnt[i]!=x) ans+=x-(ll)cnt[i];
    }
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}