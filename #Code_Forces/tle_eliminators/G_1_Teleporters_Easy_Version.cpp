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
    int n,k; 
    cin >> n>>k; 
    vector<int> v(n);
    vector<int> cost(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        cost[i]=v[i]+i+1;
    }
    sort(cost.begin(),cost.end());
    int i=0;
    int cnt=0;
    while(k>0 && i<n){
        k-=cost[i];
        if(k>=0){cnt++;}
        i++;
    }
    cout<<cnt<<endl;
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