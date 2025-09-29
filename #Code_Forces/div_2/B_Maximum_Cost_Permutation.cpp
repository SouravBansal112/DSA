#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<int> v(n);
    map<int,int> m;
    for(int i=0; i<n; i++){ 
      cin>>v[i];
      if(v[i]!=0) m[v[i]]=i;
    }
    int j=0;
    for(int i=n; i>=1; i--){
      if(m.count(i)) continue;
      while(v[j]!=0) j++;
      v[j]=i;
      m[i]=j;
    }
    pair<int,int> p=make_pair(INT_MAX,INT_MIN);
    for(int i=1; i<=n; i++){
        if(m[i]!=i-1){
            p.first= min(p.first,min(m[i]+1,i));
            p.second= max(p.second,max(m[i]+1,i));
        }
    }
    if(p.first!=INT_MAX){
        cout<<p.second-p.first+1<<endl;
    }  
    else{
        cout<<0<<endl;
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}