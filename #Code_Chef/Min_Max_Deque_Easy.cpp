#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n,q; 
    cin >> n>>q; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int mini=INT_MAX;
    int mn=INT_MAX;
    for(int i=0; i<n; i++){
        if(mini>v[i]){
            mn=mini;
            mini=v[i];
        }
        else if(mn>v[i]){
            mn=v[i];
        }
    }
    
    cout<<min(v[n-1],mn)<<endl;
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