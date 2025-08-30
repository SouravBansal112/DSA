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

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int k;
        cin>>k;
        long long int i=1;
        long long int j=9;
        long long int mul=1;
        long long int num=0;
        while(num+(i+1)*j*mul< k){
            i++;
            num+=i*j*mul;
            mul*=10;
        }
        int rem=k-num;
        int present=rem/(i+1);
        while(present!=0){
            for(int r=1; r<=9 ; r++){
                
            }
        }
        int sum=0;
        for(int i=1;i<=9; i++){
            if(mul==1){
                sum+=9;
            }
            else{
                sum+=i*mul*2;
            }
        }
        

        cout<<ans<<endl;
        
    }
    return 0;
}