#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> dp(n+1,0);
    int maxi=0;
    for(int i=0; i<n; i++){
        maxi=max(maxi,dp[i]);
        if(v[i]+i+1<=n){
            dp[v[i]+i+1]=max(dp[v[i]+i+1],maxi+v[i]+1);
        }
    }
    maxi=max(maxi,dp[n]);
    cout<<n-maxi<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}