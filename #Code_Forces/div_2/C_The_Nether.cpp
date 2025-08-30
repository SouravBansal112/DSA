#include<bits/stdc++.h>
using namespace std;

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

bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.first>b.first;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      vector<pair<int,int>> v(n+1);
      for(int i=1 ; i<=n; i++){
        cout<<"? "<<i<<" "<<n<<" ";
        for(int j=1; j<=n; j++){
            cout<<j<<" ";
        }cout<<endl<<endl;
        cin>>v[i+1].first;
        v[i+1].second=i;
      }cout<<endl<<endl;
      sort(v.begin()+1,v.end());
      cout<<"! "<<n<<" ";
      for(auto i:v){
        cout<<i.second<<" ";
      }cout<<endl;
  }
}