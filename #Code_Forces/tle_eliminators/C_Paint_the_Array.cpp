#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll gcd(ll a, ll b){
    while(a!=0){
        ll temp=a;
        a=b%a;
        b=temp;
    }
    return b;
}

void solve(){
    int n; 
    cin >> n; 
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    if(n==1){cout<<v[0]<<endl; return;}
    ll g1=v[0];
    ll g2=v[1];
    for(int i=0; i<n; i++){
        if(i%2==0){
            g1=gcd(g1,v[i]);
        }
        else{
            g2=gcd(g2,v[i]);
        }
    }
    bool flag1=true;
    bool flag2=true;
    for(int i=0; i<n; i++){
        if(i%2==0){
            if(v[i]%g2==0){
                flag2=false;
            }
        }
        else{
            if(v[i]%g1==0){
                flag1=false;
            }
        }
    }
    if(flag1){
        cout<<g1<<endl;
        return;
    }
    if(flag2){
        cout<<g2<<endl;
        return;
    }
    cout<<0<<endl;   
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}