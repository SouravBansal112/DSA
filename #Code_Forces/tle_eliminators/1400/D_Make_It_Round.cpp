#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n,m; 
    cin >> n>>m; 
    int five=0;
    int two=0;
    ll x=n;
    while(x%5==0 && x!=0){
        five++;
        x/=5;
    }
    while(x%2==0 && x!=0){
        two++;
        x/=2;
    }
    if(two>=five){
        five=two-five;
        two=0;
    }else{
        two=five-two;
        five=0;
    }
    x=1;
    while(five && x*5<=m) {x*=5ll; five--;}
    while(two && x*2<=m) {x*=2ll; two--;}
    while(x*10<=m) x*=10;
    ll mul=1;
    for(int i=2; i*x<=m;i++){
        mul=i;
    }x*=mul;
    cout<<n*x<<endl;

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}