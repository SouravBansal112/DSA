#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,m; 
    cin >> n>>m; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    vector<pair<int,int>> q(m);
    for(int i=0; i<m; i++){
        cin>>q[i].first>>q[i].second;
    }
    vector<int> dp(n+1);
    dp[0]=-1;
    dp[1]=-1;
    for(int i=2; i<n; i++){
        if(v[i]<v[i-1] && v[i-1]<v[i-2]){
            dp[i]=i-2;
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    for(int i=0; i<m; i++){
        int l=q[i].first-1;
        int r=q[i].second-1;
        if(dp[r]<l){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}