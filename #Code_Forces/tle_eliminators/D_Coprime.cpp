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
int gcd(int a, int b){
    while(a!=0){
        int temp=a;
        a=b%a;
        b=temp;
    }
    return b;
}

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    vector<int> vec(1001,-1);
    for(int i=0; i<n; i++){
        cin >> v[i];
        vec[v[i]]=i+1;
    } 
    int ans=INT_MIN;
    for(int i=1; i<1001; i++){
        for(int j=i; j<1001;j++){
            if(vec[i]!=-1 && vec[j]!=-1 && gcd(i,j)==1){
                ans=max(ans,vec[i]+vec[j]);
            }
        }
    }
    if(ans==INT_MIN){ans=-1;}
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