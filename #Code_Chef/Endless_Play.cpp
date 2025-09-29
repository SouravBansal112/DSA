#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int x,h; 
    cin >> x>>h; 
    int days=x-4;
    int hours=days*24 + h;
    cout<<hours<<endl;    
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}