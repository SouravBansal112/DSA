#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       mod           998244353
typedef       long long     ll;

ll fact(ll cnt){
    if(cnt==0) return 1;
    ll ans=1;
    while(cnt>0){
        ans=(ans*cnt)%mod;
        cnt--;
    }
    return ans;
}

void solve(){
    string s;
    cin>>s;
    ll ans=1;
    ll ans1=0;
    ll cnt=1;
    ll k=1;
    for(int i=1; i<s.length(); i++){
        if(s[i]==s[i-1]){
            cnt++;
        }
        else{
            if(cnt!=1) ans1+=cnt-1;
            k++;
            ans=(ans*cnt)%mod;
            cnt=1;
        }
    }
    if(cnt!=1) ans1+=cnt-1;
    ans=(ans*cnt)%mod;
    k=s.length()-k;
    ans*=fact(k);
    cout<<ans1<<" "<<ans%mod<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}