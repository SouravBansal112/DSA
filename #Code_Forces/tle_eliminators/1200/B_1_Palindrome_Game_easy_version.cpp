#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    string s;
    cin>>s;
    int zero=0;
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            zero++;
        }
    }
    if(zero==0){
        cout<<"DRAW"<<endl;
        return;
    }
    if(s[n/2]=='0' && n%2==1){
        if(zero==1){
            cout<<"BOB"<<endl;
        }
        else{
            cout<<"ALICE\n";
        }
    }
    else{
        cout<<"BOB\n";
    }
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