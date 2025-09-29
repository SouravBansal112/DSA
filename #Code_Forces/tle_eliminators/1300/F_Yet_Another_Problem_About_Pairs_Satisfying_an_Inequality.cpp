#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> dp(n);
    dp[0]=0;
    for(int i=1; i<n;i++){
        if(v[i-1]<i){
            dp[i]=dp[i-1]+1;
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    ll ans=0;
    for(int i=n-1; i>=0 ; i--){
        if(v[i]<i+1 && v[i]-1>=0){
            ans+=(ll)dp[v[i]-1];
        }
    }
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