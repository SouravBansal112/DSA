#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,m; 
    cin >> n>>m; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> gift(m);
    for(int i=0; i<m; i++) cin>> gift[i];
    sort(v.rbegin(),v.rend());
    int k=0;
    ll ans=0;
    for(int i=0; i<n; i++){
        if(k+1<=v[i]){
            ans+=(ll)gift[k];
            k++;
            continue;
        }
        ans+=(ll)gift[v[i]-1];
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