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
    vector<int> v(n);
    int neg=0;
    bool zero=false;
    int mini=INT_MAX;
    ll sum=0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        mini=min(mini,abs(v[i]));
        sum=sum+(ll)abs(v[i]);
        if(v[i]<0){
            neg++;
        }
        if(v[i]==0){
            zero=true;
        }
    }
    if(zero || neg%2==0){
        cout<<sum<<endl;
        return;
    }
    cout<<sum-2*mini<<endl;
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