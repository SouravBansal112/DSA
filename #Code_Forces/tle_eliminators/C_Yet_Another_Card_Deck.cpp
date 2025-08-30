#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n,q; 
    cin >> n>>q; 
    vector<int> v(n);
    map<int,int> m;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(m.count(x)){
            continue;
        }
        m[x]=i+1;
    }
    vector<int> query(q);
    for(int i=0; i<q; i++) cin >> query[i];
    for(int i=0; i<q; i++){
        cout<<m[query[i]]<<" ";
        for(auto &j:m){
            if(j.second<m[query[i]]){
                j.second=j.second+1;
            }
        }
        m[query[i]]=1;
    }cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}