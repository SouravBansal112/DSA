#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
*/
/*
for(int i=0 ; i<n ; i++){

}
*/
void solve(){
    int n; 
    cin >> n; 
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    int ans=1;
    int cnt=1;
    pair<int,int> p=make_pair(0,0);
    bool flag=false;
    for(int i=1; i<n; i++){
        if(b[i]>=b[i-1]){
            cnt++;
            if(cnt>1 && a[i]<a[i-1]){
                flag=true;
            }
        }
        else{
            if(cnt>ans){
                ans=cnt;
                p.first=i-cnt+1;
                p.second=i;
            }
            if(flag){
                p.first=i-cnt+1;
                p.second=i;
                cout<<p.first<<" "<<p.second<<endl;
                return;
            }
            cnt=1;
        }
    }
    if(flag || cnt>=ans){
        ans=cnt;
        p.first=n-cnt+1;
        p.second=n;
    }
    cout<<p.first<<" "<<p.second<<endl;
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