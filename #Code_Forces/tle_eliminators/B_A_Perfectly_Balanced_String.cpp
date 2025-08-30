#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    string v;
    set<char> m;
    for(int i=0; i<n; i++) {
        if(m.count(s[i])){
            continue;
        }
        m.insert(s[i]);
        v.push_back(s[i]);
    }
    int i=0;
    while(i<n){
        for(int j=0; j<v.length() && i<n ; j++,i++){
            if(s[i]==v[j]){
                continue;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;   
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