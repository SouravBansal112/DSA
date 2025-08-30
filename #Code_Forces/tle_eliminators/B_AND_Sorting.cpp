#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int ans=(1 << 31)-1;
    vector<int> vec;
    for(int i=0; i<n; i++){
        if(v[i]!=i){
            vec.push_back(v[i]);
        }
    }
    for(int i=0; i<vec.size(); i++){
        ans&=vec[i];
    }
    cout<<ans<<endl;
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