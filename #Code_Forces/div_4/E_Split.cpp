#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,k; 
    cin >> n>>k;
    vector<int> v(n);
    map<int,int> m;
    for(int i=0; i<n; i++){
        cin>>v[i];
        m[v[i]]++;
    } 
    for(auto &i:m){
        if(i.second%k!=0){
            cout<<0<<endl;
            return;
        }
    }
    ll ans=0;
    int l=0;
    map<int,int> cnt;
    for(int r=0;r<n; r++){
        cnt[v[r]]++;
        if(cnt[v[r]]>m[v[r]]/k){
            while(cnt[v[r]]>m[v[r]]/k){
                ans+=(ll)(r-l);
                cnt[v[l]]--;
                l++;
            }
        }
    }
    ans+=(ll)(n-l)*(n-l+1)/2;
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