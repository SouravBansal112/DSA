#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    ll a,b; 
    cin >> a>>b; 
    if(b%2==0 && (a%2==0 || b%4==0)){
        cout<<a*(b/2)+2<<endl;
        return;
    }
    if(a%2==1 && b%2==1){
        cout<<a*b+1<<endl;
        return;
    }
    if(b%2==1 && a%2==0){
        cout<<-1<<endl; 
        return;
    }
    if(b%2==0 && a%2==1 && b%4!=0){
        cout<<-1<<endl;
        return;
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}