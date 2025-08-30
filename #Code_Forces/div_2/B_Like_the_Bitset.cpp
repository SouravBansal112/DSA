#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
*/
/*
for(int i=0 ; i<n ; i++){

}
*/
void solve(){
    int n,k; 
    cin >> n>>k;
    string s;
    cin>>s;
    vector<int> v(n);
    int mini=1;
    int one=0;
    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            one++;
        }
    }
    int maxi=one+1;
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            v[i]=maxi;
            maxi++;
        }
        else{
            v[i]=mini;
            mini++;
        }
    }
    int cnt = 0, ans = 0;
    for (char c : s) {
        if (c == '1') {
            cnt++;
            ans = max(ans, cnt);
        } else {
            cnt = 0;
        }
    }
    if(ans>=k){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++){
            cout<<v[i]<<" ";
        }cout<<endl;
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