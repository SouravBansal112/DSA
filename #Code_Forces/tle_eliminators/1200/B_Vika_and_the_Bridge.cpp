#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n,k; 
    cin >> n>>k; 
    vector<int> v(n);
    map<int,priority_queue<int>> m;
    vector<int> last(n+1,-1);
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(last[v[i]]!=-1){
            m[v[i]].push(i-last[v[i]]-1);
        }
        else{
            m[v[i]].push(i);
        }
        last[v[i]]=i;
    }
    for(auto &i:m){
        i.second.push(n-1-last[i.first]);
    }
    for(auto &i:m){
        int top=i.second.top();
        i.second.pop();
        i.second.push(top/2);
    }
    int ans=INT_MAX;
    for(auto &i:m){
        ans=min(ans,i.second.top());
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