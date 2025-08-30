#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    ll n,l,r; 
    cin >> n>>l>>r; 
    vector<ll> v(n);
    for(int i=1; i<=n; i++)
    {
        int x= r-(r%i);
        v[i-1]=x;
        if(x<l){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0; i<n ;i++){
        cout<<v[i]<<" ";
    }cout<<endl;
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