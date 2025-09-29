#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n,x; 
    cin >> n>>x;
    if(x<= n*(n+1)/2){
        ll ans=0;
        int s=0;
        int e=n;
        ll mid= s+(e-s)/2;
        while(s<=e){
            mid= s+(e-s)/2;
            ll key= mid*(mid+1)/(ll)2;
            if(key<=x){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        if(ans*(ans+1)/2<x && ans+1<=2*n-1) ans++;
        cout<<ans<<endl;
        return;
    }
    ll init= n*(n+1)/2;
    ll ans=0;
    x-=init;
    int s=0;
    int e=n-1;
    ll mid=s+(e-s)/2;
    while(s<=e){
        mid=s+(e-s)/2;
        ll key=(mid*(2ll*n-1ll-mid))/(ll)2;
        if(key<=x){
            s=mid+1;
            ans=mid;
        }
        else{
            e=mid-1;
        }
    }
    if((ans*(2*n-1-ans))/2<x && n+ans+1<=2*n-1) ans++;
    cout<<n+ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}