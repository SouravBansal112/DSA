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
bool check(vector<int> &v, int &def){
    int i=0;
    int j=v.size()-1;
    while(i<=j){
        if(v[i]%def==v[j]%def){
            i++;
            j--;
            continue;
        }
        return false;
    }
    return true;
}


void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int i=0;
    int j=n-1;
    while(i<j && (v[i]==v[j])){
        i++;
        j--;
    }
    if(i>=j){cout<<0<<endl; return;}
    int def= max(v[i],v[j])-min(v[i],v[j]);
    bool flag=check(v,def);
    if(flag){cout<<def<<endl; return;}
    int ans=1;
    for(int i=2; i*i<=def; i++){
        if(def%i==0){
            flag=check(v,i);
            if(flag){ans=max(ans,i);}
            int x=def/i;
            flag=check(v,x);
            if(flag){ans=max(ans,x);}

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