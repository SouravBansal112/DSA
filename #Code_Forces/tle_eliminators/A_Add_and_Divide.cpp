#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int cnt=0;
        if(b==1){
            b++;
            cnt++;
        }
        int x=a;
        int y=b;
        int maxi=0;
        while(x!=0){
            maxi++;
            x=x/y;
        }
        int ans=maxi+cnt;
        int op=0;
        for(int i=1; i<maxi; i++){
            op=0;
            int x=a;
            int y=b+i;
            while(x>0){
                op++;
                x=x/y;
            }
            ans=min(ans,cnt+i+op);
        }
        cout<<ans<<endl;
    }
}