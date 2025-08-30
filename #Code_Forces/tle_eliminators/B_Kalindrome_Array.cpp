#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
bool palin(vector<int> &v,int i,int j){
    while(i<=j){
        if(v[i]==v[j]){
            i++;
            j--;
            continue;
        }
        return false;
    }
    return true;
}

bool kalin(vector<int> &v, int i, int j, int &x){
    while(i<j){
        if(v[i]==v[j]){
            i++;
            j--;
        }
        else if(v[i]==x){
            i++;
        }
        else if(v[j]==x){
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    bool check= palin(v,0,n-1);
    if(check || n==2){
        cout<<"YES"<<endl;
        return;
    }
    int s=0;
    int e=n-1;
    while(v[s]==v[e]){
        s++;
        e--;
    }
    int i=s;
    int j=e;
    bool flag1=false;
    bool flag2=false;
    while(v[i]==v[s]){
        i++;
    }
    if(v[i]==v[e]){
        flag1=kalin(v,i,e,v[s]);
    }
    while(v[j]==v[e]){
        j--;
    }
    if(v[j]==v[s]){
        flag2=kalin(v,s,j,v[e]);
    }
    if(flag1 || flag2){
        cout<<"YES"<<endl;
        return;
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