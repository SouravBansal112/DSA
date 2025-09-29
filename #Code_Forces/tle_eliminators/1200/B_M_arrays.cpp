#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n,x; 
    cin >> n>>x; 
    vector<int> v(n);
    map<int,int> m;
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(m.count(v[i]%x)) m[v[i]%x]++;
        else m[v[i]%x]=1;
    }
    ll ans=0;
    if(x%2==0 && m.count(x/2)) ans++;
    if(m.count(0)) ans++;
    for(int i=1; i<=x-1; i++){
        int a=i;
        int b=x-a;
        if(!m.count(a)) continue;
        if(a==b) continue;
        if(m.count(a) && !m.count(b)){
            ans+=m[a];
            continue;
        }
        if(i>x/2) continue;
        if(m[a]==m[b])ans++;
        else{
            ans+=(ll)max(m[a],m[b])-(ll)min(m[a],m[b]);
        }
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



