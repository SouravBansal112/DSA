#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    int ans=0;
    if(n%2==0) ans=(n/2+1)*((n+1)/2+1);
    else ans=2*(n/2+1)*((n+1)/2+1);
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}