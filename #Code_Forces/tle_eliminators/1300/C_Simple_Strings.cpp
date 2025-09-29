#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    string change= "abcdefghijklmnopqrstuvwxyz";
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1]){
            int j=0;
            while(change[j]==s[i-1] || (i+1<n && change[j]==s[i+1])) j++;
            s[i]=change[j];
        }
    }
    cout<<s<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}