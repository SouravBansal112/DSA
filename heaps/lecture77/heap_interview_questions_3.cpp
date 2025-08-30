#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range.*/

class node{
    public:
    int data;
    int i;
    int j;
    node(int data,int row,int col){
        this->data = data;
        i=row;
        j=col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<node*, vector<node*>, compare > p;
    int maxi=INT_MIN;
    for(int i=0 ; i<k ; i++){
        node* tmp= new node(a[i][0],i,0);
        if(tmp->data > maxi){
            maxi=tmp->data;
        }
        p.push(tmp);
    }
    int mini=p.top()->data;
    int amin=mini;
    int amax=maxi;
    int ans=amax-amin;
    while(!p.empty()){
        node* tmp=p.top();
        p.pop();
        mini=tmp->data;
        if(maxi-mini < amax-amin){
            amax=maxi;
            amin=mini;
            ans=amax-amin;
        }
        if(tmp->j +1 < n){
            node* temp=new node(a[tmp->i][tmp->j+1],tmp->i,tmp->j+1);
            maxi = max(maxi,temp->data);
            p.push(temp);
        }
        else{
            break;
        }
    }
    return ans;

}

/*Given that integers are read from a data stream. Your task is to find the median of the elements read so far.

Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.*/

void median(int element,priority_queue<int, vector<int> , greater<int> > &min,priority_queue<int> &max,int &med){
	if(element > med){
		min.push(element);
	}
	else{
		max.push(element);
	}

    if (max.size() > min.size() + 1) {
        min.push(max.top());
        max.pop();
    } else if (min.size() > max.size() + 1) {
        max.push(min.top());
        min.pop();
    }

    if(min.size()==max.size()){
		med= (min.top() + max.top()) /2;
	}
	else if(min.size()>max.size()){
		med= min.top();
	}
	else{
		med = max.top(); 
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	int med=0;
	vector<int> ans;
	priority_queue<int, vector<int> , greater<int> > min;
	priority_queue<int> max;
	for(int i=0 ; i<n ; i++){
		median(arr[i],min,max,med);
		ans.push_back(med);
	}
	return ans;
}















