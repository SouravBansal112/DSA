#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

int sz(vector<int> a, vector<int> b){
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    int ans=INT_MAX;
    int cnt=0;
    for(int i=0; i<a.size(); i++){
        int it= lower_bound(b.begin(),b.end(),a[i])-b.begin();
        if(it==0){ ans=i; break;}
        if(ans>(it+i)) ans=it+i;
        if(ans==i)break;
    }
    return ans;
}

void solve(){
    int n,m; 
    cin >> n>>m; 
    vector<int> a(n);
    vector<int> b(n);
    a[0]=1;
    for(int i=1; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    int ans=sz(b,a);
    cout<<n-ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}