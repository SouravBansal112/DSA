#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007;
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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans=1;
    for(int i=n-1; i>=0; i--){
        int x=upper_bound(a.begin(),a.end(),b[i])-a.begin();
        int av=n-x-(n-1-i);
        ans=(ans*av)%MOD;
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