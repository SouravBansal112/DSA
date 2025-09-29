#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,k; 
    cin >> n>>k; 
    string s; cin>>s;
    int ans=0;
    vector<int> vis(n,0);
    int i=0;
    int j=n-1;
    while(i<j){
        if(vis[i]){
            i++;
            j--;
            continue;
        }
        int st=i;
        int en=j;
        vector<int> cnt(26,0);
        bool flag=false;
        int tot=0;
        while(st<=j){
            if(st==j) flag=true;
            cnt[s[st]-'a']++;
            vis[st]=1;
            st+=k;
            tot++;
        }
        if(!flag){
            while(en>=i){
                vis[en]=1;
                cnt[s[en]-'a']++; en-=k; tot++;
            }
        }
        int maxi=0;
        for(int l=0; l<26; l++) maxi=max(maxi,cnt[l]);
        ans+=tot-maxi;
        i++; j--;
    }cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}