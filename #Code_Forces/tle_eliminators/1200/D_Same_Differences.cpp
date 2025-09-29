#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n; i++){
        v[i]=v[i]-(i+1);
    }
    sort(v.begin(),v.end());
    ll init=1;
    ll ans=0;
    for(int i=1; i<n; i++){
        if(v[i]==v[i-1]){
            init++;
        }
        else{
            ans+= init*(init-1)/2;
            init=1;
        }
    }
    ans+=init*(init-1)/2;
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