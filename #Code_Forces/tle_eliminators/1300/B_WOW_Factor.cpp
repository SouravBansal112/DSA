#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    string s;
    cin>>s;
    string st;
    for(int i=1; i<s.length(); i++){
        if(s[i]=='v' && s[i-1]=='v'){
            st.push_back('w');
        }
        if(s[i]=='o'){
            st.push_back('o');
        }
    }
    int n=st.length();
    ll wcnt=0;
    vector<ll> cnt(n+1);
    cnt[n]=0;
    for(int i=n-1; i>=0; i--){
        if(st[i]=='w'){
            wcnt++;
            cnt[i]=cnt[i+1];
            continue;
        }
        cnt[i]=cnt[i+1]+wcnt;
    }
    ll ans=0;
    for(int i=0; i<n-2; i++){
        if(st[i]=='w'){
            ans+=cnt[i];
        }
    }
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}