#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int ans=v[0];
    int one=0;
    for(int i=1; i<n; i++){
        if(v[i]==1) one++;
        else{
            ans+= (one/3);
            one =0;
        }
    }ans+=one/3;
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