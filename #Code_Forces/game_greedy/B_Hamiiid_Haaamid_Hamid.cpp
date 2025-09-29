#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n,x; 
    cin >> n>>x; 
    string s;
    cin>>s;
    int i=x;
    while(i<n && s[i]!='#') i++;
    i++;
    int j=x-1;
    while(j>=0 && s[j]!='#') j--;
    j++;
    if((i>n && j<1) || x==1 || x==n){
        cout<<1<<endl;
        return;
    }
    cout<<min(min(x,n-x+1),max(n-i+2,j+1))<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}