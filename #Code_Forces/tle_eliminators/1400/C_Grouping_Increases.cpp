#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    stack<int> a;
    stack<int> b;
    a.push(INT_MAX);
    b.push(INT_MAX);
    int cnt=0;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        if(x>a.top() && x>b.top()){
            cnt++;
            if(a.top()<b.top()) a.push(x);
            else b.push(x);
        }
        else if(x<=a.top() && x<=b.top()){
            if(a.top()<b.top()) a.push(x);
            else b.push(x);
        }
        else if(x>a.top() && x<=b.top()){
            b.push(x);
        }
        else if(x<=a.top() && x>b.top()){
            a.push(x);
        }
    }
    cout<<cnt<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}