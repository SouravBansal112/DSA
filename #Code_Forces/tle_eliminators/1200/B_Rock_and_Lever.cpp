#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

int getbit(int n){
    int cnt=0;
    while(n!=0){
        n=n/2;
        cnt++;
    }
    return cnt;
}

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    ll ans=0;
    vector<int> bit(32,0);
    for(int i=0; i<n; i++){
        bit[getbit(v[i])]++;
    }
    for(int i=1; i<32; i++){
        if(bit[i]>0){
            ans+= (ll)bit[i]*(ll)(bit[i]-1)/2;
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