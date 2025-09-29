#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,m; 
    cin >> n>> m; 
    map<int,vector<int>> a;
    map<int,vector<int>> b;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            a[x].push_back(i+1);
            b[x].push_back(j+1);
        }
    }
    ll sum=0;
    for(auto &i:a){
        sort(i.second.rbegin(),i.second.rend());
    }
    for(auto &i:b){
        sort(i.second.rbegin(),i.second.rend());
    }
    for(auto &i:a){
        int sz= i.second.size()-1;
        for(int j=0; j<sz; j++){
            sum+=(ll)(j+1)*(ll)(i.second[j]-i.second[j+1])*(ll)(sz-j);
        }
    }
    for(auto &i:b){
        int sz= i.second.size()-1;
        for(int j=0; j<sz; j++){
            sum+=(ll)(j+1)*(ll)(i.second[j]-i.second[j+1])*(ll)(sz-j);
        }
    }
    cout<<sum<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}