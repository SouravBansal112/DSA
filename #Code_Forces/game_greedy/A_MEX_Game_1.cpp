#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    int x=0;
    map<int,int> cnt;
    for(int i=0; i<n; i++){
        if(cnt.count(v[i]) && (v[i]==x || i>0 && v[i-1]==v[i])) cnt[v[i]]++;
        else if(v[i]==x || i>0 && v[i-1]==v[i]) cnt[v[i]]=1;
        if(v[i]==x){
            x++;
        }
        else if(i>0 && v[i-1]==v[i]){
            continue;
        }
        else{
            break;
        }
    }
    if(x==0){cout<<0<<endl; return;}
    int ans=INT_MAX;
    int num=0;
    for(auto i:cnt){
        if(i.second<2 && num<2){
            ans=i.first;
            num++;
        }
    }
    if(num==2){
        x= ans;
    }
    cout<<x<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}