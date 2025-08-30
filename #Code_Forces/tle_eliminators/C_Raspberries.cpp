#include <iostream>
#include<vector>
#include<climits>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        int k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0 ; i<n ; i++){
            cin>>v[i];
        }
        int rem=INT_MAX;
        bool flag=false;
        for(int i=0 ; i<n ; i++){
            if(v[i]%k==0){
                cout<<0<<endl;
                flag=true;
                break;
            }
            int x=((v[i]/k)+1)*k -v[i];
            rem=min(rem,x);
        }
        if(flag){continue;}
        int cnt2=0;
        int add=0;
        if(k==4){
            for(int i=0 ; i<n ; i++){
                if(v[i]%2==0){
                    cnt2++;
                }
            }
            add=cnt2>=2? 0:2-cnt2;
            rem=min(rem,add);
        }
        cout<<rem<<endl;
    }
    return 0;
}