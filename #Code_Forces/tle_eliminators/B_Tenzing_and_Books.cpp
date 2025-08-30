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
// vector<int> getbits(int n){
//     int cnt=0;
//     vector<int> m;
//     while(n!=0){
//         if(n%2==1){
//             m.push_back(cnt);
//         }
//         n=n/2;
//         cnt++;
//     }
//     return m;
// }

// bool check(vector<int> &source, vector<int> &target){
//     int i=0;
//     int j=0;
//     while(i < source.size() && j < target.size()){
//         if(source[i]==target[j]){
//             i++;
//             j++;
//         }
//         else if(source[i]<target[j]){
//             i++;
//         }
//         else{
//             return false;
//         }
//     }
//     return j == target.size();
// }

// void accumulate(int &init,vector<int> &a, vector<int> &source, int &x){
//     for(int i=0; i<a.size(); i++){
//         if(a[i]>x){
//             return;
//         }
//         vector<int> target=getbits(a[i]);
//         bool flag=check(source,target);
//         if(flag){
//             init|=a[i];
//         }
//         else{
//             return;
//         }
//     }
// }

void accumulate2(int &init, vector<int> &stack, int x) {
    for (int v : stack) {
        if ((v | x) != x) break;
        init |= v;
    }
}

void solve(){
    int n,x; 
    cin >> n>>x;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    int init=0;
    accumulate2(init,a,x);
    accumulate2(init,b,x);
    accumulate2(init,c,x);
    if(init==x){
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