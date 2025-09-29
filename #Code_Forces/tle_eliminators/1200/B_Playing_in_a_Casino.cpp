#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n,m; 
    cin >> n>>m; 
    vector<vector<int>> v(m,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[j][i];
        }
    }
    for(int i=0; i<m; i++){
        sort(v[i].begin(),v[i].end());
    }
    ll ans=0;
    for(int i=0; i<m; i++){
        ll cnt=1;
        ll rem=v[i].size()-1;
        for(int j=0; j<n-1; j++){
            ll def=v[i][j+1]-v[i][j];
            ans+=def*cnt*rem;
            cnt++;
            rem--;
        }
    }
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}