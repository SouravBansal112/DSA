#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> a(n);
    vector<int> ida(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        ida[i]=i;
    }
    vector<int> b(n);
    vector<int> idb(n);
    for(int i=0; i<n; i++){
        cin >> b[i];
        idb[i]=i;
    }
    vector<int> c(n);
    vector<int> idc(n);
    for(int i=0; i<n; i++){
        cin >> c[i];
        idc[i]=i;
    }
    sort(ida.begin(),ida.end(),[&](int i, int j){
        return a[i]>a[j];
    });
    sort(idb.begin(),idb.end(),[&](int i, int j){
        return b[i]>b[j];
    });
    sort(idc.begin(),idc.end(),[&](int i, int j){
        return c[i]>c[j];
    });
    ida.resize(3);
    idb.resize(3);
    idc.resize(3);
    int ans=0;
    for(int i=0;i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(ida[i]!=idb[j] && idb[j]!=idc[k] && ida[i]!=idc[k]){
                    ans=max(ans,a[ida[i]]+b[idb[j]]+c[idc[k]]);
                }
            }
        }
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