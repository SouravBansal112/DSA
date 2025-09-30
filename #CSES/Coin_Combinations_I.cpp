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
    int n,x; 
    cin >> n>>x; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(),v.end());
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int i=0; i<x; i++){
        for(int j=0; j<n && i+v[j]<=x; j++){
            dp[i+v[j]]=(dp[i+v[j]]+dp[i])%MOD;
        }
    }cout<<dp[x]<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}