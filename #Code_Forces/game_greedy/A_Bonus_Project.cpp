#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n,k; 
    cin >> n>>k; 
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> b[i];
    vector<int> c(n);
    int sum=0;
    for(int i=0; i<n; i++){
        c[i]= a[i]/b[i];
        sum+=c[i];
    }
    if(sum<k) {
        for(int i=0; i<n; i++){
            cout<<0<<" ";
        }cout<<endl;
        return;
    }
    int extra=sum-k;
    for(int i=0; i<n; i++){
        if(c[i]<=extra){
            extra-=c[i];
            c[i]=0;
            continue;
        }
        c[i]-=extra;
        extra=0;
    }
    for(int i=0; i<n; i++){
        cout<<c[i]<<" ";
    }cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}