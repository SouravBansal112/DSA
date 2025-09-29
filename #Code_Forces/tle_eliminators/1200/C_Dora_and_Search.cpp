#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int s=1;
    int e=n;
    int i=0;
    int j=n-1;
    while(i<j){
        int maxi=e;
        int mini=s;
        if(v[i]!=maxi && v[i]!=mini && v[j]!=maxi && v[j]!=mini){
            cout<<i+1<<" "<<j+1<<endl;
            return;
        }
        if(v[i]==maxi){
            i++;
            e--;
        }
        if(v[i]==mini){
            i++;
            s++;
        }
        if(v[j]==maxi){
            j--;
            e--;
        }
        if(v[j]==mini){
            j--;
            s++;
        }
    }
    cout<<-1<<endl;
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