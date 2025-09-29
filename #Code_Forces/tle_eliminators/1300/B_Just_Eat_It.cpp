#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<ll> v(n);
    bool neg=false;
    ll sum=0;
    for(int i=0; i<n; i++){ 
        cin>>v[i];
        if(v[i]<0ll) neg=true;
        sum+=v[i];
    }
    if (!neg && sum!=0) {
        cout<<"YES"<<endl;
        return;
    }
    vector<ll> pre(n);
    pre[0]=v[0];
    for(int i=1; i<n; i++) pre[i]=pre[i-1]+v[i];
    ll maxi=pre[0];
    ll minp=0;
    for(int i=1; i<n-1; i++){
        maxi=max(maxi,pre[i]-minp);
        minp=min(minp,pre[i]);
    }
    ll maxi2=v[1];
    minp=min(v[0],pre[1]);
    for(int i=2; i<n; i++){
        maxi2=max(maxi2,pre[i]-minp);
        minp=min(minp,pre[i]);
    }
    if(maxi>=sum || maxi2>=sum) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}