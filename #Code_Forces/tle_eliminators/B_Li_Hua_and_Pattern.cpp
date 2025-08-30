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
    ll n,k; 
    cin >>n>>k;  
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    } 
    if(n==1){cout<<"YES"<<endl; return;}
    ll cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]!=v[n-1-i][n-1-j]){
                cnt++;
            }
        }
    }
    cnt=(cnt+1)/2;
    if(cnt>k){
        cout<<"NO"<<endl;
        return;
    }
    if(cnt<k){
        if((k-cnt)%2==1 && n%2==0){
            cout<<"NO"<<endl;
            return;
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