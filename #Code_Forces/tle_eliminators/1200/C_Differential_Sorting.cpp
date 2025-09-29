#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    bool sorted=true;
    for(int i=1; i<n; i++){
        if(v[i]>= v[i-1]){
            continue;
        }
        else{
            sorted=false;
            break;
        }
    }
    if(sorted){cout<<0<<endl; return;}
    if(v[n-2]>v[n-1]){
        cout<<-1<<endl; 
        return;
    }
    int mini=v[n-2]-v[n-1];
    int ans=0;
    for(int i=n-3; i>=0; i--){
        if(mini<=v[i+1]){
            v[i]=mini;
            ans++;
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans<<endl;
    for(int i=0; i<n-2;i++){
        cout<<i+1<<" "<<n-1<<" "<<n<<endl;
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