#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,m,k; 
    cin >> n>>m>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> seg;
    for(int i=1; i<n; i++) seg.push_back(v[i]-v[i-1]-1);
    sort(seg.rbegin(),seg.rend());
    ll ans=v[n-1]-v[0]+1;
    int i=0;
    k--;
    while(k--){
        int x=seg[i];
        ans-=x;
        i++;
    }
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}

