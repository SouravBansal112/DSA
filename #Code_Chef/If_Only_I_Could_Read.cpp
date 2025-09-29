#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    bool flag=true;
    for(int i=1; i<n; i++){
        if(v[i]<v[i-1]){
            flag=false;
            break;
        }
    }
    if(flag){cout<<-1<<endl; return;}
    for(int i=0; i<n-1; i++){
        
    }
    cout<<-1<<endl;
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