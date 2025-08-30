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
    string s;
    cin>>s;
    ll n=s.size();
    ll one=0;
    ll maxi=0;
    ll f=0;
    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            one++;
        }
        else{
            if(f==0){
                f=one;
            }
            maxi=max(maxi,one);
            one=0;
        }
    }
    maxi=max(maxi,one);
    if(s[0]=='1' && s[n-1]=='1'){
        maxi=max(f+one,maxi);
    }
    if(maxi==n){
        cout<<(ll)n*n<<endl;
        return;
    }
    if(maxi==1 || maxi==0){
        cout<<maxi<<endl;
        return;
    }
    ll ans=0;
    for(int i=0; i<maxi; i++){
        ans=max(ans,(maxi-i)*(1+i));
    }
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