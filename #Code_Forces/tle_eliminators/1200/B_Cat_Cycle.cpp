#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;
 
void solve(){
    ll n,k; 
    cin >> n>>k; 
    if(n%2==0){
        int ans=k%n==0?n:k%n;
        cout<<ans<<endl;
        return;
    }
    k--;
    int x=n/2;
    int i= k+(k/x);
    i= i%n+1;
    cout<<i<<endl;
}
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}