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
        long long int n;
        cin>>n;
        long long int x = (log(n) / log(3) + 1e-9);
        long long int y = pow(3,x);
        long long int rem = n-y;
        long long int coins= pow(3,x+1) + x*(pow(3,x-1));
        while(rem!=0){
            x = (log(rem) / log(3) + 1e-9);
            y = pow(3,x);
            rem=rem-y;
            coins+=pow(3,x+1) + x*(pow(3,x-1));
        }
        coins += rem;
        cout << coins << endl;
    }
    return 0;
}
//#include <bits/stdc++.h> using namespace std; /* vector<int> v(n); for(int i=0 ; i<n ; i++){ cin>>v[i]; } */ /* for(int i=0 ; i<n ; i++){ } */ int main(){ int t; cin>>t; while(t--){ long long int n; cin>>n; long long int x = log(n) / log(3); long long int y = pow(3,x); long long int rem = n-y; long long int coins= pow(3,x+1) + x*(pow(3,x-1)); while(rem!=0){ x = log(rem) / log(3); y = pow(3,x); rem=rem-y; coins+= pow(3,x+1) + x*(pow(3,x-1)); } coins+=rem; cout<<fixed<<coins<<endl; } return 0; }
