#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void dfs(int u, map<int,vector<pair<int,int>>> &adj,vector<int> &id,vector<int> &dp){
    for(auto j:adj[u]){
        if(id[j.first]==0){
            dp[j.first]=dp[u]+ (j.second<id[u]);
            id[j.first]=j.second;
            dfs(j.first,adj,id,dp);
        }
    }
}

void solve(){
    int n; 
    cin >> n; 
    vector<pair<int,int>> v(n-1);
    vector<int> dp(n+1,0);
    vector<int> id(n+1,0);
    map<int,vector<pair<int,int>>> adj;
    for(int i=0; i<n-1; i++) {
        cin>>v[i].first>>v[i].second;
        adj[v[i].second].push_back({v[i].first,i+1});
        adj[v[i].first].push_back({v[i].second,i+1});
    }
    dp[1]=1;
    dfs(1,adj,id,dp);
    int ans=0;
    for(int i=1; i<=n;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}

