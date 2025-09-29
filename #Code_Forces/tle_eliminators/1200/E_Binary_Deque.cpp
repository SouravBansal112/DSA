#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n,s; 
    cin >> n>>s; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int sum=0;
    map<int,int> f;
    f[0]=-1;
    for(int i=0; i<n; i++){
        sum+=v[i];
        if(f.count(sum)){
            continue;
        }
        f[sum]=i;
    }
    sum=0;
    map<int,int> b;
    b[0]=n;
    for(int i=n-1; i>=0; i--){
        sum+=v[i];
        if(b.count(sum)){
            continue;
        }
        b[sum]=i;
    }
    if(sum<s){cout<<-1<<endl; return;}
    if(sum==s){cout<<0<<endl; return;}
    int d=sum-s;
    int ans=INT_MAX;
    for(int i=0; i<=d; i++){
        int x=f[i]+1;
        int y=n-b[d-i];
        ans=min(ans,x+y);
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