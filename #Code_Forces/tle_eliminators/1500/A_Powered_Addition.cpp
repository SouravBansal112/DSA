#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

int msb(int x){
    int cnt=0;
    while(x>0){
        x/=2;
        cnt++;
    }return cnt;
}

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int maxi=v[0];
    int time=0;
    for(int i=1; i<n; i++){
        if(v[i]>=maxi){
            maxi=v[i];
            continue;
        }
        time= max(time,msb(maxi-v[i]));
    }cout<<time<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}