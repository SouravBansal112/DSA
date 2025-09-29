#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

ll modpow(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }return res%MOD;
}

ll dfs(int i, map<int,vector<pair<int,int>>> &adj,ll &exc,vector<int> &vis,ll &k){
    vis[i]=1;
    ll res=0;
    for(auto j:adj[i]){
        if(vis[j.first]!=1){
            ll x=dfs(j.first,adj,exc,vis,k);
            if(j.second==0) res+=x;
            else exc= (exc+modpow(x,k))%MOD;
        }
    }
    return res+1;
}

void solve(){
    ll n,k; 
    cin >> n>>k;
    map<int,vector<pair<int,int>>> adj;
    for(int i=0; i<n-1; i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    vector<int> vis(n+1,0);
    ll tot=modpow(n,k);
    ll exc=0;
    ll x=dfs(1,adj,exc,vis,k);
    exc= (exc+modpow(x,k))%MOD;
    cout<<((tot - exc) % MOD + MOD) % MOD<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
