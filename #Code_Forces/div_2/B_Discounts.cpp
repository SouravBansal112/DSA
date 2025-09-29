#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n,k; 
    cin >> n>>k;
    vector<ll> v(n);
    vector<ll> c(k);
    for(int i=0; i<n; i++) cin>>v[i]; 
    for(int i=0; i<k; i++) cin>>c[i];
    sort(v.rbegin(),v.rend());
    sort(c.begin(),c.end());
    int j=0;
    ll ans=0;
    for(int i=0; i<n; i++){
        if(j<k && c[j]!=1){
            ans+=v[i];
            c[j]--;
        }
        else if(j<k && c[j]==1){
            j++;
        }
        else{
            ans+=v[i];
        }
    }
    // int j=0;
    // int cnt=1;
    // ll ans=0;
    // for(int i=0; i<n; i++){
    //     if(c[j]!=cnt){
    //         ans+=v[i];
    //         cnt++;
    //     }
    //     else if(j<k && c[j]==cnt){
    //         cnt=1;
    //         j++;
    //     }
    // }
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