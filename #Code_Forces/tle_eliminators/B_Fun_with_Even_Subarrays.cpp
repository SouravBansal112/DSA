#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int x=v[n-1];
    int cnt=0;
    int length=1;
    for(int i=n-2; i>=0;){
        if(v[i]==x){
            length++;
            i--;
            continue;
        }
        cnt++;
        i=i-length;
        length*=2;
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