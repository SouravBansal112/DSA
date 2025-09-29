#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    map<int,int> m;
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(m.count(x)){
            m[x]++;
            if(v.size()>=m[x]){
                v[m[x]-1].push_back(x);
            }
            else{
                v.push_back(vector<int> (1,x));
            }
        }
        else{
            m[x]=1;
            if(v.size()>=1){
                v[0].push_back(x);
            }
            else{
                v.push_back(vector<int> (1,x));
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        sort(v[i].begin(),v[i].end());
    }
    int init=v.size();
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size()-1; j++){
            if(v[i][j+1]-v[i][j]>1){
                init++;
            }
        }
    }
    cout<<init<<endl;
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