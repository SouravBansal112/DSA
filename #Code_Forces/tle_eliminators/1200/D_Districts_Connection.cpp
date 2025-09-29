#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    int cnt=1;
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(i>0 && v[i]==v[0]) cnt++;
    } 
    if(cnt==n){
        cout<<"NO"<<endl;
        return;
    }
    int x;
    vector<int> a;
    cout<<"YES"<<endl;
    for(int i=1;i<n;i++){
        if(v[i]!=v[0]){
            cout<<1<<" "<<i+1<<endl;
            x=i+1;
        }
        else a.push_back(i+1);
    }
    for(int i=0; i<a.size(); i++){
        cout<<x<<" "<<a[i]<<endl;
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