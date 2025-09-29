#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void get(int x,vector<int> &bits){
    int cnt=0;
    while(x!=0){
        bits[cnt]=x%2;
        x/=2;
        cnt++;
    }
}

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int x=-1;
    for(int i=0; i<n; i++) x&=v[i];
    ll cnt=0;
    for(int i=0; i<n; i++) if(v[i]==x) cnt++;
    if(cnt<2){cout<<0<<endl; return;}
    ll ans= (cnt*(cnt-1))%MOD;
    for(ll i=1; i<=n-2; i++) ans=(ans*i)%MOD;
    cout<<ans%MOD<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}