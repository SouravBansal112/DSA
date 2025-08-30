#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int candy=0;
    int i=0;
    int j=n-1;
    int left=v[0];
    int right=v[n-1];
    while(i<j){
        if(left<right){
            i++;
            left+=v[i];
        }
        else if(left>right){
            j--;
            right+=v[j];
        }
        if(left==right){
            candy=i+1+n-j;
            i++;
            j--;
            if(i<j){
                left+=v[i];
                right+=v[j];
            }
        }
    }
    cout<<candy<<endl;
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