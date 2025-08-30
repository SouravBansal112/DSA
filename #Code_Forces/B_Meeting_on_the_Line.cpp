#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> x(n),t(n);
        for(int i=0; i<n; i++){
            cin>>x[i];
        }
        for(int i=0; i<n; i++){
            cin>>t[i];
        }
        long long int maxi = LLONG_MIN; // max(x[i] + t[i])
        long long int mini = LLONG_MAX; // min(x[i] - t[i])
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, x[i] + t[i]);
            mini = min(mini, x[i] - t[i]);
        }
        double ans = ( (double)maxi + (double)mini ) / 2.0;
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}

// pair<double,double> segment(int i,vector<double> &x,vector<double> &t,double &T){
//     return make_pair(x[i]-T+t[i],x[i]+T-t[i]);
// }

// bool overlap(pair<double,double> &itr,pair<double,double> &seg){
//     if(itr.first<seg.second && itr.second >= seg.first){
//         itr.first=seg.first;
//         return true;
//     }
//     else if(itr.second>seg.first && itr.first <=seg.second){
//         itr.second=seg.second;
//         return true;
//     }
//     else if(itr.first >= seg.first && itr.second <= seg.second){
//         return true;
//     }
//     else if(itr.first <= seg.first && itr.second >= seg.second){
//         itr.first=seg.first;
//         itr.second=seg.second;
//         return true;
//     }
//     return false;
// }

// void intersect(pair<double,double> &itr,pair<double,double> &seg,double &T){ 
//     if(itr.second < seg.first){
//         int dif = seg.first - itr.second;
//         if(dif%2==0){ 
//             itr.first=itr.second + dif/2; 
//             itr.second=itr.first; 
//             T+=dif; return; 
//         } 
//         else{ 
//             itr.first=itr.second + (double)dif/2.0; 
//             itr.second=itr.first; 
//             T+=(double)dif/2.0; 
//             return; 
//         } 
//     } 
//     else if(itr.first > seg.second){ 
//         int dif = itr.first - seg.second; 
//         if(dif%2==0){ 
//             itr.first=seg.second + dif/2; 
//             itr.second=itr.first; T+=dif; 
//             return; 
//         } else{ 
//             itr.first=seg.second + (double)dif/2.0; 
//             itr.second=itr.first; 
//             T+=(double)dif/2.0; 
//             return; 
//         } 
//     } 
// }


//         double T=0;
//         for(int i=0; i<n; i++){
//             T=max(T,t[i]);
//         }
//         pair<double,double> itr=segment(0,x,t,T);
//         for(int i=0; i<n ; i++){
//             pair<double,double> seg=segment(i,x,t,T);
//             if(overlap(itr,seg)){
//                 continue;
//             }
//             else{
//                 intersect(itr,seg,T);
//             }
//         }
//         cout<<itr.first<<endl;