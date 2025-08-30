#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
*/
/*
for(int i=0 ; i<n ; i++){

}
*/

bool cmp(pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b){
  if(a.first.second==a.first.second){
    return a.first.first < b.first.first;
  }
  return a.first.second < b.first.second;
}

void solve(){
    int n; 
    cin >> n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];
    vector<vector<int>> pos(n+1);
    for(int i=1; i<=n; i++){
      pos[v[i]].push_back(i);
    }
    vector<pair<pair<int,int>,int>> it;
    for(int i=1 ; i<=n; i++){
      int blocks=pos[i].size()/i;
      for(int j=0; j<blocks; j++){
        int s= pos[i][j*blocks];
        int e= pos[i][j*blocks +blocks-1];
        it.push_back(make_pair(make_pair(s,e),blocks));
      }
    }
    sort(it.begin(),it.end(),cmp);

    

    
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
