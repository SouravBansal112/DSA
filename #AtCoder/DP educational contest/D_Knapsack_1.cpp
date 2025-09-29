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
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];
    vector<vector<ll>> dp(n+1,vector<ll>(W+1,0));
    for(int i=1; i<=n; i++){
        for(int c=1; c<=W; c++){
            if(w[i-1]<=c){
                dp[i][c]=max(dp[i-1][c],dp[i-1][c-w[i-1]]+v[i-1]);
            }
            else{
                dp[i][c]=dp[i-1][c];
            }
        }
    }cout<<dp[n][W]<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}