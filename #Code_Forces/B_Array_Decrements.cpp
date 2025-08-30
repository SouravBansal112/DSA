#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;

        bool bad = false;
        int dif = -1;

        for(int i = 0; i < n; i++){
            if(b[i] > a[i]){ bad = true; break; }
            if(b[i] != 0){
                if(dif == -1) dif = a[i] - b[i];
                if(a[i] - b[i] != dif){ bad = true; break; }
            }else{
                if(dif != -1 && a[i] - b[i] > dif){ bad = true; break; }
            }
        }
        cout << (bad ? "NO\n" : "YES\n");
    }
}




