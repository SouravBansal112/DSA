#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n; 
    cin >> n;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            cout<<n/i<<" "<<n-n/i<<endl;
            return;
        }
    }
    cout<<1<<" "<<n-1<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}