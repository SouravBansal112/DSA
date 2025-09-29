#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n, y; 
    cin >> n>>y;
    vector<int> v(n);
    unordered_map<int,int> original;
    for(int i=0; i<n; i++){ 
      cin>>v[i];
      original[v[i]]++;
    }
    set<int> cdt;
    for (int val : v) {
        for (int k = 1; k * k <= val; k++) {
            int q1 = val / k;  
            int q2 = k;         
            if (q1 > 1) cdt.insert(q1);
            if (q2 > 1) cdt.insert(q2);
        }
    }
    if(cdt.empty()) cdt.insert(1);
    ll ans=LLONG_MIN;
    int x=0;
    for(auto i: cdt){
        ll sum=0;
        ll init=0;
        unordered_map<int,int> used = original;
        for(int j=0; j<n; j++){
            int np = (v[j] + i - 1) / i;  // correct ceil
            sum += np;
            if(used[np]>0){
                used[np]--;
            }else{
                init++;
            }
        }
        if(ans<sum-init*y) x=i;
        ans=max(ans, sum-init*y);

    }
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