#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    bool five=false;
    bool two=false;
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(v[i]%5==0) five=true;
        if(v[i]%2==0) two=true;
    }
    if(five){
        for(int i=0; i<n; i++) if(v[i]%10!=0) v[i]+=5;
        for(int i=0; i<n-1; i++){ if(v[i]!=v[i+1]){cout<<"No"<<endl; return;}}
        cout<<"Yes"<<endl; return;
    }
    for(int i=0; i<n; i++) v[i]%=20;
    for(int i=0; i<n; i++){
        while(v[i]%10!=2){
            v[i]+= v[i]%10;
        }
        v[i]%=20;
    }
    for(int i=0; i<n-1; i++){
        if(v[i]!=v[i+1]){
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}