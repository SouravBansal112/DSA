#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    string s;
    cin>>s;
    vector<int> pref(n);
    pref[0]=v[0];
    int zero=s[0]=='0'?v[0]:0;
    int one=s[0]=='1'?v[0]:0;
    for(int i=1; i<n; i++) {
        pref[i]=v[i]^pref[i-1];
        if(s[i]=='1') one^=v[i];
        else zero^=v[i];
    }
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        if(x==2){
            int g;
            cin>>g;
            if(g==1) cout<<one<<" ";
            else cout<<zero<<" ";
            continue;
        }
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        one^= l-1>=0?(pref[l-1]^pref[r]):pref[r];
        zero^= l-1>=0?(pref[l-1]^pref[r]):pref[r];
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