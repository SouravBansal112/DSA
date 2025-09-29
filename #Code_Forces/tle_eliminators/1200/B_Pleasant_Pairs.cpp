#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    ll ans=0;
    for(int i=0; i<n; i++){
        for(int j=1; v[i]*j-(i+1)<=n; j++){
            int x=v[i]*j -(i+1);
            if(i<x-1 && v[x-1]==j){
                ans++;
            }
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