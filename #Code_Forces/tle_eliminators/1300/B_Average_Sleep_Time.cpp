#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,k; 
    cin >> n>>k;
    vector<double> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    double ans=0;
    for(int i=0; i<n; i++){
        if(i+1<k && i+1>n-k+1){
            ans+= (v[i]*(n-k+1));
        }
        else if(i+1<k){
            ans+=(v[i]*(i+1));
        }
        else if(i+1>=n-k+1){
            ans+=(v[i]*(n-i));
        }
        else{
            ans+=(v[i]*k);
        }
    }
    cout<<fixed<<setprecision(10)<<ans/(double)(n-k+1)<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}