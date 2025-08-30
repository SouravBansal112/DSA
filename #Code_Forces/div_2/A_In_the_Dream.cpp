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
    int a,b,c,d; 
    cin >> a>>b>>c>>d;
    c=c-a;
    d=d-b;
    if(a>b){
        swap(a,b);
        swap(c,d);
    }
    if(b/2<=a || b%2==0 && b/2-1<=a){
        if(d>c){
            if(d/2<=c || d%2==0 && d/2-1<=c){
                cout<<"YES"<<endl;
                return;
            }
        }
        else{
            if(c/2<=d || c%2==0 && c/2-1<=d){
                cout<<"YES"<<endl;
                return;
            }
        }
        
    }
    cout<<"NO"<<endl;
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