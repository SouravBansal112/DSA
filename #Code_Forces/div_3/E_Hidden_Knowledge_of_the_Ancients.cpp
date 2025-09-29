#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

ll at(vector<int> &v,int k,int maxl){
    int left=0;
    map<int,int> m;
    ll res=0;
    for(int right=0; right<v.size(); right++){
        m[v[right]]++;
        while(m.size()>k){
            m[v[left]]--;
            if(m[v[left]]==0) m.erase(v[left]);
            left++;
        }
        int sz= (right-left+1);
        if(sz>maxl) {left+=(sz-maxl); sz=maxl;}
        res+=sz;
    }
    return res;
}

void solve(){
    ll n,k,l,r; 
    cin >> n>>k>>l>>r; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    ll ans= at(v,k,r) - at(v,k,l-1);
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}
















