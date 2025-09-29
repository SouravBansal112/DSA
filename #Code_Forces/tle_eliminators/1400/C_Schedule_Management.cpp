#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

bool pos(vector<int> &v, ll &time){
    ll ava=0;
    ll left=0;
    for(int i=0; i<v.size(); i++){
        ll task=v[i];
        if(time==task) continue;
        if(time> task) ava+= (time-task)/2;
        else left+= (task-time);
    }
    return left<=ava;
}


void solve(){
    int k,n; 
    cin >> k>>n; 
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        v[i]--;
    }
    vector<int> cnt(k,0);
    for(int i=0; i<n; i++) cnt[v[i]]++;
    ll time=LLONG_MAX;
    int s=0;
    int e=n;
    ll mid= s+(e-s)/2;
    while(s<=e){
        mid= s+(e-s)/2;
        if(pos(cnt,mid)){
            e=mid-1;
            time=mid;
        }
        else{
            s=mid+1;
        }
    }
    cout<<time<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}