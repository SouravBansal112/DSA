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
    int n,a,b; 
    cin >> n>>a>>b;
    if(a>n || b>n ){cout<<"NO"<<endl;}
    if(n%2==0){
        if((b%2==0 && b>=a) || (b%2==0 && a%2==0)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
        if((b%2==1 && b>=a) || (b%2==1 && a%2==1)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }    
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
