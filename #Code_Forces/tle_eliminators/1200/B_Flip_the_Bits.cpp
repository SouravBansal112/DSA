#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    string a,b;
    cin>>a>>b;
    vector<int> v;
    int one=0;
    int zero=0;
    for(int i=0; i<n; i++){
        if(a[i]=='0') zero++;
        else one++;
        if(one==zero) v.push_back(i);
    }
    int j=0;
    bool same=a[0]==b[0];
    for(int i=0; i<n; i++){
        if( j<v.size() && v[j]==i){
            if(a[i]==b[i] && !same || a[i]!=b[i] && same){
                cout<<"NO"<<endl;
                return;
            }
            j++;   
            same=i<n-1 && a[i+1]==b[i+1];
            continue;
        }
        if(j>=v.size()){
            if(a[i]!=b[i]){
                cout<<"NO"<<endl;
                return;
            }
        }
        else if(a[i]==b[i] && !same || a[i]!=b[i] && same){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){ solve();}
  return 0;
}