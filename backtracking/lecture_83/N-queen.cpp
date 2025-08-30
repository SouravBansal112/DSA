#include <bits/stdc++.h>
using namespace std;

void solve(int i,int n,vector<vector<int>> &v,vector<vector<int>> &ans,vector<bool> &col,vector<bool> &dig1,vector<bool> &dig2){
	if(i==n){
		vector<int> temp;
		for(int x=0 ; x<n; x++){
			for(int y =0; y<n ; y++){
				temp.push_back(v[x][y]);
			}
		}
		ans.push_back(temp);
		return;
	}

	for(int j=0 ; j<n ; j++){
		if(col[j]==1 && dig1[i+j]==1 && dig2[n-1+j-i]==1)
		{
			v[i][j]=1;
			col[j]=0;
			dig1[i+j]=0;
			dig2[n-1+j-i]=0;
			solve(i+1,n,v,ans,col,dig1,dig2);
			v[i][j]=0;
			col[j]=1;
			dig1[i+j]=1;
			dig2[n-1+j-i]=1;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> v(n,vector<int> (n,0));
	vector<vector<int>> ans;
	vector<bool> col(n,1);
	vector<bool> dig1(2*n-1,1);
	vector<bool> dig2(2*n-1,1);

	solve(0,n,v,ans,col,dig1,dig2);
	return ans;
	
}














