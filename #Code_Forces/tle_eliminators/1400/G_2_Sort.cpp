#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,k; 
    cin >> n>>k; 
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int i=n-2;
    bool flag=false;
    ll ans=0;
    int cnt=0;
    while(i>=0){
        if(flag){
            if(v[i]< 2ll*v[i+1]) ans++;
            else flag=false;
        }
        else{
            if(v[i]< 2ll*v[i+1]) cnt++;
            else cnt=0;
            if(cnt==k){
                ans++;
                flag=true;
                cnt=0;
            }
        }
        i--;
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