#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n;
    cin >> n; 
    vector<int> uni(n);
    vector<int> skill(n);
    map<int,vector<ll>> m;
    for(int i=0; i<n; i++) cin>>uni[i];
    for(int i=0; i<n; i++) cin>>skill[i];
    for(int i=0; i<n; i++) m[uni[i]].push_back(skill[i]);
    for(auto &i: m) sort(i.second.rbegin(),i.second.rend());
    for(auto &i: m) {
        for(int j=1;j<i.second.size(); j++){
            i.second[j]+=i.second[j-1];
        }
    }
    vector<ll> pref(n+1,0);
    for(auto i:m){
        int k=1;
        int sz=i.second.size();
        while(sz/k>0){
            pref[k]+= i.second[(sz/k)*k-1];
            k++;
        }
    }
    for(int k=1; k<=n; k++) cout<<pref[k]<<" ";
    cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}