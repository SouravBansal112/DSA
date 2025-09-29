#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        vector<int> temp(x);
        for(int j=0; j<x; j++){
            cin>>temp[j];
        }
        v.push_back(temp);
    }
    map<int,int> cnt;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cnt[v[i][j]]++;
        }
    }
    for(int i=0; i<v.size(); i++){
        bool flag=true;
        for(int j=0; j<v[i].size(); j++){
            if(cnt[v[i][j]]==1){
                flag=false;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}