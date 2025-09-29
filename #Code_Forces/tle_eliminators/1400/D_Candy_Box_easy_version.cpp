#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<int> v(n+1,0);
    for(int i=0; i<n; i++) {
      int x;
      cin>>x;
      v[x]++;
    }
    map<int,int> m;
    for(int i=1; i<=n; i++){
      if(v[i]!=0) m[v[i]]++;
    }
    int inc=n;
    ll ans=0;
    for(int i=n; i>=1; i--){
      if(!m.count(i)) continue;
      if(i<inc) inc=i;
      int freq=m[i];
      while(freq>0 && inc>0){
        ans+=inc;
        freq--; inc--;
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
