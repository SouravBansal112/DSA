#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int dfs(int i, map<int,vector<int>> &adj,vector<int> &vis, int &ans){
    vis[i]=1;
    int res=1;
    for(int j:adj[i]){
        if(!vis[j]){
            res+=dfs(j,adj,vis,ans);
        }
    }
    if(res%2==0) {ans++; res=0;}
    return res;
}

void solve(){
    int n; 
    cin >> n; 
    map<int,vector<int>> adj;
    vector<int> vis(n+1,0);
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v; 
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans=0;
    dfs(1,adj,vis,ans);
    if(n%2==0 || ans==0) ans--;
    if(n%2==1) ans=-1;
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}