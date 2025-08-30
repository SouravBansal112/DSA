#include<bits/stdc++.h>
using namespace std;

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

bool cmp(long long int &a,long long int &b){
    return a>b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      priority_queue<long long int> q;
      for(int i=0; i<n ; i++){
        int x;
        cin>>x;
        q.push(x);
      }
      long long int ans=0;
      for(int i=1; i<n; i++){
        long long int top=q.top();
        ans+=top;
        q.pop();
        q.pop();
        q.push(0);
      }
      cout<<ans<<endl;  
  }
}