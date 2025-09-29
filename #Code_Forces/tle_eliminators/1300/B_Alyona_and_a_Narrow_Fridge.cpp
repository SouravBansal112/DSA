#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,h; 
    cin >> n>>h;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int ans=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<=i; j++){
            if(v[j]>v[i]){
                rotate(v.begin()+j,v.begin()+i,v.begin()+i+1);
                break;
            }
        }
        int acc=0;
        int e=i;
        int height=h;
        while(e-1>=0 && height-max(v[e],v[e-1])>=0){
            height-=max(v[e],v[e-1]);
            e-=2;
            acc+=2;
        }
        if((e>=0 && v[e]<=height) || (e-1>=0 && v[e-1]<=height))acc++;
        if (acc==i+1) ans=i+1;
        
    }
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}