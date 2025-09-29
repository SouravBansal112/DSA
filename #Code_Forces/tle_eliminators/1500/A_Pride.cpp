#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int mini=INT_MAX;
    int cnt=0;
    for(int l=0; l<n; l++){
        if(v[l]==1) cnt++;
        int r=l+1;
        int g=v[l];
        while(r<n && g!=1){
            g=gcd(g,v[r]);
            r++;
        }r--;
        if(g==1) mini=min(mini,r-l+1);
    }
    if(cnt){
        cout<<n-cnt<<endl;
    }
    else if(mini!=INT_MAX){
        cout<<n-1+mini-1<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}