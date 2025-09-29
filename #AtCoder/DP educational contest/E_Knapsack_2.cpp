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
    int n,W; 
    cin >> n>>W; 
    vector<ll> v(n);
    vector<int> w(n);
    ll V=0;
    for(int i=0; i<n; i++) {cin>>w[i]>>v[i]; V+=v[i];}
    vector<vector<ll>> dp(n+1,vector<ll>(V+1,LLONG_MAX/2));
    dp[0][0]=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=V; j++){
            if(v[i-1]<=j){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i-1]]+w[i-1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    ll ans=0;
    for(int i=1; i<=V; i++){
        if(dp[n][i]<=W){
            ans=i;
        }
    }cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}