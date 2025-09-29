#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void getbits(vector<int> &zerobits,int x ){
    int cnt=0;
    while(x!=0){
        if(x%2==1){
            zerobits[cnt]--;
        }
        x=x/2;
        cnt++;
    }
}

ll getnum(int x){
    return (1ll << x);
}

void solve(){
    ll n,k;
    cin >> n>>k;
    vector<ll> v(n);
    ll ans=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
    } 
    vector<int> zerobits(32,n);
    for(int i=0; i<n; i++){
        getbits(zerobits,v[i]);
    }
    for(int i=30; i>=0; i--){
        if(k>=zerobits[i] || zerobits[i]==0){
            k-=zerobits[i];
            ans+=getnum(i);
        }
    }
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}