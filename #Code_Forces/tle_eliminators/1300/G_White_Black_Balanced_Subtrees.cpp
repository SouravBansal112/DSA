#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

int dfs(map<int,vector<int>> &m, int i,string &s,int &res){
    if(!m.count(i)){
        if(s[i-1]=='W') return 1;
        else return -1;
    }
    int ans=s[i-1]=='W'? 1:-1;
    for(auto j:m[i]){
        ans+=dfs(m,j,s,res);
    }
    if(ans==0){
        res++;
    }
    return ans;
}

void solve(){
    int n; 
    cin >> n; 
    map<int,vector<int>> m;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        m[x].push_back(i);
    }
    string s;
    cin>>s;
    int res=0;
    dfs(m,1,s,res);
    cout<<res<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}