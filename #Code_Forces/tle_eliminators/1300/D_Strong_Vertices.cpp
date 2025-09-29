#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> b(n);
    for(int i=0; i<n; i++) cin>>b[i];
    for(int i=0; i<n;i++) a[i]-=b[i];
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        if(a[i]>maxi) maxi=a[i];
    }
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(a[i]==maxi){
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}