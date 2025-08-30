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
ll gcd(ll a,ll b){
    while(b!=0){
        ll temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    vector<ll> pref(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    } 
    pref[0]=v[0];
    for(int i=1; i<n; i++){
        pref[i]=pref[i-1]+(ll)v[i];
    } 
    ll ans=INT_MIN;
    for(int i=0; i<n-1; i++){
        ans=max(ans,gcd(pref[i],pref[n-1]-pref[i]));
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