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
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> dp(n,INT_MAX);dp[0]=0;
    for(int i=1; i<n; i++){
        for(int j=max(0,i-k); j<i; j++){
            dp[i]=min(dp[i],dp[j]+abs(v[i]-v[j]));
        }
    }cout<<dp[n-1]<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  while(t--) solve();
  return 0;
}