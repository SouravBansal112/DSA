#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n,m; 
    cin >> n>>m; 
    vector<int> v;
    for(int i=1; i<=n;i++){
        for(int j=1;j<=m;j++){
            int a= i <= (n+1)/2 ? n-i: i-1;
            int b= j <= (m+1)/2 ? m-j: j-1;
            v.push_back(a+b);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n*m; i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}