#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SpecialStack {

    stack<int> s;
    int mini= INT_MAX;

    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            mini=data;
        }
        else {
            if (data > mini){
            s.push(data);
            }
            else{
                s.push(2*data-mini);
                mini=data;
            }
        }
        
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty()){
            return -1;
        }
        else{
            int curr= s.top();

            if(s.top()>mini){
                s.pop();
                return curr;
            }
            else{
                int prevmini= mini;
                mini= 2*mini- curr;
                s.pop();
                return prevmini;
            }
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr>mini){
            return curr;
        }
        else{
            return mini;
        }
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty())
            return-1;
        return mini;
    }  
};