#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(),v.end());
    ll move=0;
    ll charge=0;
    int i=0;
    int j=v.size()-1;
    while(i<=j){
        if(i==j){
            if(v[i]==1) {move++;break;}
            move+=((charge+v[i]+1)/2)-charge+1;
            break;
        }
        if(charge==v[j]){
            move++;
            charge=0;
            j--;
        }
        while(charge+v[i]<=v[j]){
            charge+=v[i];
            move+=v[i];
            i++;
        }
        if(charge+v[i]>=v[j] && i!=j){
            v[i]-=v[j]-charge;
            move+=v[j]-charge+1;
            charge=0;
            j--;
        }
    }
    cout<<move<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}