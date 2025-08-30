#include<bits/stdc++.h>
using namespace std;

/*
for(int i=0; i<n ;i++){
  
}
*/
/*
vector<int> v(n);
*/


int main(){
        int n,x,y;
        cin>>n>>x>>y;
        int k= y/x;
        int rem= n%k == 0 ? 0:1;
        cout<<(n/k)+rem<<endl;
}