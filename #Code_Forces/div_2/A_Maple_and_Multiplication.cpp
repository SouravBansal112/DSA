#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

void solve(){
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return;
    }
    if(max(a,b)%min(a,b)==0){
        cout<<1<<endl;
    }
    else{
        cout<<2<<endl;
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