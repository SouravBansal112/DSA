#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    map<int,vector<int>> cnt;
    for(int i=0; i<n; i++){
        cin >> v[i];
    } 
    for(int i=0; i<n ; i++){
        cnt[v[i]].push_back(i);
    }
    for(auto i=cnt.begin(); i!=cnt.end(); ++i){
        if(i->second.size()%i->first!=0){
            cout<<-1<<endl;
            return;
        }
    }
    vector<int> ans(n);
    int x=1;
    for(auto i=cnt.begin(); i!=cnt.end(); ++i){
        int val=i->first;
        int s= i->second.size();
        vector<int> temp=i->second;
        for(int j=0; j<s; j+=val){
            for(int k=0; k<val ;k++){
                ans[temp[j+k]]=x;
            }x++;
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
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