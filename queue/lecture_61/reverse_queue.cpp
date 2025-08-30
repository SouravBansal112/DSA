#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse_queue(queue<int> &q){

    if(q.empty()){
        return;
    }

    int element= q.front();
    q.pop();
    reverse_queue(q);
    q.push(element);
    return;

}
