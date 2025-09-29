#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    vector<int> len(n+1,-1);
    vector<int> prev(n+1,0);
    for(int i=0; i<n; i++) {
        cin>>v[i];
        len[v[i]]=max(len[v[i]],(i+1)-prev[v[i]]);
        prev[v[i]]=i+1;
    }
    map<int,int> m;
    for(int i=1; i<=n; i++){
        len[i]=max(len[i],n-prev[i]+1);
        if(len[i]!=-1){
            if(m.count(len[i])) m[len[i]]=min(m[len[i]],i);
            else m[len[i]]=i;
        } 
    }
    int mini=INT_MAX;
    for(int i=1; i<=n; i++){
        if(m.count(i)){
            mini=min(mini,m[i]);
        }
        if(mini==INT_MAX) cout<<-1<<" ";
        else cout<<mini<<" ";
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