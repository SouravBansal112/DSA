#include<bits/stdc++.h>
using namespace std;

#define             MOD             1000000007;
typedef             long long       ll;

int cnt(string &s,int &i,int &j,char c){
    int st=i;
    int e=j;
    int ans=0;
    while(st<e){
        if(s[st]==s[e]){
            st++;
            e--;
            continue;
        }
        if(s[st]==c){
            st++;
            ans++;
        }
        else if(s[e]==c){
            e--;
            ans++;
        }
        else{
            return INT_MAX;
        }
    }
    return ans;
}


void solve(){
    int n; 
    cin >> n; 
    string s;
    cin>>s;
    int i=0;
    int j=n-1;
    while(i<j && s[i]==s[j]){i++; j--;}
    if(i>=j){cout<<0<<endl; return;}
    int ans= min(cnt(s,i,j,s[i]),cnt(s,i,j,s[j]));
    if(ans==INT_MAX){cout<<-1<<endl; return;}
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