#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];    
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}

    // int n; 
    // cin >> n;
    // vector<int> v(n);
    // vector<int> scnt(n+1,0);
    // vector<int> parent(n+1);
    // for (int i = 1; i <= n; i++) parent[i] = i;
    // for(int i=0; i<n-1; i++){
    //     int u,v,x,y;
    //     cin>>u>>v>>x>>y;
    //     if(x>y){
    //         unite(u,v,scnt,parent);
    //     }
    //     else {
    //         unite(u,v,scnt,parent);
    //     }
    // }  
    // vector<pair<int,int>> vec;
    // int cnt=1;
    // for(int i=1; i<=n; i++){
    //     vec.push_back(make_pair(i,scnt[i]));
    // }
    // sort(vec.begin(),vec.end(), [](auto &a, auto &b) {
    //     return a.second < b.second;
    // });
    // for(int i=1; i<=n; i++){
    //     v[vec[i-1].first-1]=cnt;
    //     cnt++;
    // }
    // for(int i=0; i<n; i++)cout<<v[i]<<" ";
    // cout<<endl;