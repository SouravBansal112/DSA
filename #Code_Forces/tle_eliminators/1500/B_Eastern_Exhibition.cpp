#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> x(n);
    vector<int> y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];
    if(n%2==1){cout<<1<<endl; return;}
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    ll a= x[n/2]-x[n/2-1]+1;
    ll b= y[n/2]-y[n/2-1]+1;
    cout<<(ll)a*b<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}