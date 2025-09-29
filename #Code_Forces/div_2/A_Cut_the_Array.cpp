#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<int> v(n);
    vector<int> pref(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i==0) pref[i]=v[i];
        else pref[i]=v[i]+pref[i-1];
    }
    for(int l=0; l<n-2; l++){
        for(int r=l+1; r<n-1; r++){
            int s1 = ((pref[l] % 3) + 3) % 3;
            int s2 = ((pref[r] - pref[l]) % 3 + 3) % 3;
            int s3 = ((pref[n-1] - pref[r]) % 3 + 3) % 3;
            if(s1!=s2 && s1!= s3 && s2!=s3){
                cout<<l+1<<" "<<r+1<<endl;
                return;
            }
            if(s1==s2 && s1==s3){
                cout<<l+1<<" "<<r+1<<endl;
                return;
            }
        }
    } 
    cout<<0<<" "<<0<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}