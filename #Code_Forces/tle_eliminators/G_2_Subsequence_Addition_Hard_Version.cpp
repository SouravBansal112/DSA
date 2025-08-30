#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
*/
/*
for(int i=0 ; i<n ; i++){

}
*/
void solve(){
    int n; 
    cin >> n; 
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    if(v[0]!=1){cout<<"NO"<<endl; return;}
    vector<ll> pref(n);
    pref[0]=1;
    for(int i=1; i<n; i++){pref[i]=pref[i-1]+v[i];}
    for(int i=1; i<n ; i++){
        if(v[i]<=pref[i-1]){
            continue;
        }
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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