#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n;
    char c; 
    cin >> n>>c;
    string s;
    cin>>s; 
    bool flag=true;
    for(int i=0; i<n; i++){
        if(s[i]!=c){
            flag=false;
        }
    }
    if(flag){cout<<0<<endl; return;}
    int div=2;
    while(div<=n){
        bool found=true;
        for(int i=1; div*i<=n; i++){
            if(s[div*i-1]!=c){
                found=false;
                break;
            }
        }
        if(found){cout<<1<<endl<<div<<endl; return;}
        div++;
    }
    cout<<2<<endl;
    cout<<n<<" "<<n-1<<endl;
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