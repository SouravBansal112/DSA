#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,m; 
    cin >> n>>m; 
    vector<pair<int,int>> v;
    vector<int> dp(n+1,n+1);
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        v.push_back({x,y});
        dp[x]=min(dp[x],y);
    }
    ll ans=0;
    for(int i=n-1; i>=1; i--){
      dp[i]=min(dp[i+1],dp[i]);
    }
    for(int i=1; i<=n; i++){
      ans+=dp[i]-i;
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