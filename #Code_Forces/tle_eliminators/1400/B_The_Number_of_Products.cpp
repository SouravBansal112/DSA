#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<int> pref(n+1,0);
    vector<int> even(n+1,0);
    vector<int> odd(n+1,0);
    vector<int> v(n);
    even[0]=1;
    for(int i=0; i<n; i++){
      cin>>v[i];
    }
    for(int i=1; i<=n; i++){
      pref[i]= v[i-1]<0? pref[i-1]+1:pref[i-1];
      even[i]= pref[i]%2==0? even[i-1]+1:even[i-1];
      odd[i]= pref[i]%2==1? odd[i-1]+1:odd[i-1];
    }
    ll neg=0;
    ll pos=0;
    for(int i=1; i<=n; i++){
      if(pref[i]%2==0){
        pos+=even[i-1];
        neg+=odd[i-1];
      }
      else{
        pos+=odd[i-1];
        neg+=even[i-1];
      }
    }
    cout<<neg<<" "<<pos<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  while(t--) solve();
  return 0;
}

