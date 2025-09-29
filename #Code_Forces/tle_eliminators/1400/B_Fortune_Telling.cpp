#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n,x,y; 
    cin >> n>>x>>y;
    vector<int> v(n);
    int odd=0;
    for(int i=0; i<n; i++){ 
        cin>>v[i];
        if(v[i]%2==1) odd++;
    }
    if(y%2==0){
        if((x%2==0 && odd%2==0) || (x%2==1 && odd%2==1)){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
    else{
        if((x%2==0 && odd%2==1) || (x%2==1 && odd%2==0)){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}
