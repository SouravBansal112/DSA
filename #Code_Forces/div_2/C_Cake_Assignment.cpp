#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

ll power(ll a, ll k){
    ll res=1;
    while(k>0){
        if(k & 1) res=res*a;
        a=a*a;
        k/=2;
    }
    return res;
}

void solve(){
    ll k,x;
    cin>>k>>x;
    ll a=2;
    a=power(a,k);
    ll b=a;
    if(a==x){
        cout<<0<<endl<<endl;
        return;
    }
    if(a<x){
        int cnt=0;
        while(a+b/2!=x){
            b=b+a/2;
            a/=2;
            cnt++;
        }
        cnt++;
        cout<<cnt<<endl;
        while(cnt>1){
            cout<<1<<" ";
            cnt--;
        }
        cout<<2<<endl;
        return;  
    }
    int cnt=0;
    while(b/2!=x && a>x){
        b=b+a/2;
        a/=2;
        cnt++;
    }
    cnt++;
    cout<<cnt<<endl;
    while(cnt>1){
        cout<<2<<" ";
        cnt--;
    }
    cout<<1<<endl;
    return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}