#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i]; 
    for(int i=0; i<n; i++){
        for(int i=0; i<n; i++){
            if(v[i]>0) {
                v[i]--;
            }
        }
        bool flag=false;
        for(int i=0; i<n; i++){
            if(i-1>=0 && v[i]!=0 && v[i-1]==0 && flag){
                cout<<"NO"<<endl;
                return;
            }
            if(v[i]!=0) flag=true;
        }
    }   
    cout<<"YES"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}
