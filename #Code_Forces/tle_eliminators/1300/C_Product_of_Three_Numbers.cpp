#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            int a=i;
            int b=n/i;
            for(int j=a+1;j*j<b; j++){
                if(b%j==0 && b/j!=a){
                    cout<<"YES"<<endl;
                    cout<<a<<" "<<j<<" "<<b/j<<endl;
                    return;
                }
            }
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}