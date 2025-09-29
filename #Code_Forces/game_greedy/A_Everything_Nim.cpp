#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v;
    set<int> s;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(s.count(x)){
            continue;
        }
        s.insert(x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(v.size()==1 || v[0]>1){cout<<"Alice"<<endl; return;}
    int cnt=1;
    for(int i=1; i<v.size(); i++){
        if(v[i]-v[i-1]==1){
            cnt++;
        }
        else{
            break;
        }
    }
    if(cnt<v.size()){
        if(cnt%2==1){
            cout<<"Bob"<<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }
    }
    else{
        if(cnt%2==0){
            cout<<"Bob"<<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }     
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}