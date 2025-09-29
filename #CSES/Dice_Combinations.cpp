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
    ll n; 
    cin >> n; 
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for(int i=0; i<=n; i++){
        for(int j=1; j<=6 && i+j<=n ; j++){
            dp[i+j]=(dp[i+j]+dp[i])%MOD;
        }
    }cout<<dp[n]<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}