#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    int x=(n*(n-1))/2;
    vector<int> v(x);
    for(int i=0; i<x; i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<int>());
    int cnt=2;
    cout<<v[0]<<" "<<v[0]<<" ";
    int i=0;
    while(i<x){
        i=i+cnt;
        if(i<x){
            cout<<v[i]<<" ";
        }
        cnt++;
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