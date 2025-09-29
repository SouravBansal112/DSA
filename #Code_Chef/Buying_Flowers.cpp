#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    int ans=n/3;
    int rem=n%3;
    if(n==2){
        cout<<4<<endl;
        return;
    }
    if(rem==1){
        ans--;
        ans=ans*5 +8;
    }
    else if(rem==2){
        ans=ans*5 +4;
    }
    else{
        ans*=5;
    }
    cout<<ans<<endl;
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