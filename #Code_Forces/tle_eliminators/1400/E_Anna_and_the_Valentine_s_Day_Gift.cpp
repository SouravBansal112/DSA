#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,m; 
    cin >> n>>m ; 
    vector<int> v(n);
    int non=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        int x=v[i];
        int zero=0;
        bool flag=false;
        while(x!=0){
            if(flag){
                non++;
                x/=10;
                continue;
            }
            if(x%10==0){
                x/=10;
                zero++;
            } 
            else flag = true;
        }
        v[i]=zero;
    } 
    sort(v.rbegin(),v.rend());
    for(int i=0; i<n; i++){
        if(i%2==1) non+=v[i]; 
    }
    if(non>m)cout<<"Sasha"<<endl;
    else cout<<"Anna"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}