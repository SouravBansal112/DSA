#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> dp(n,1);
    dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=2; j*i<=n; j++){
            if(v[j*i-1]>v[i-1]){
                dp[j*i-1]=max(dp[j*i-1],dp[i-1]+1);
            }
        }
    }
    int maxi=INT_MIN;
    for(int i=0; i<n; i++) maxi=max(maxi,dp[i]);
    cout<<maxi<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}