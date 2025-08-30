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
    int n; 
    cin >> n;  // read input for the problem
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    ll ans=0;
    for(int i=1; i<n; i=i+2){
        if(a[i-1]>a[i]){
            ans+= a[i-1]-a[i];
            a[i-1]=a[i];
        }
        ll s = a[i-1];
        if(i+1<n){
            s+=a[i+1];}
        if(s>a[i]){
            ans+=s-a[i];
            if(s-a[i]> a[i+1]){
                a[i+1]=0;
                a[i-1]= a[i-1]-(s-a[i]-a[i+1]);
            }
            else{
                a[i+1]-=s-a[i];
            }
        }
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