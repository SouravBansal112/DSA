#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

/*Given a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
Note: The tree contains unique values.*/

Node* createMap(map<Node *, Node *> &m, Node *root,int target)
{   
   Node *res= NULL;
   queue<Node*> q;
   q.push(root);
   m[root]=NULL;
   while(!q.empty()){
       Node *front=q.front();
       q.pop();
       if(front->left){
           m[front->left] = front;
           q.push(front->left);
       }
       if(front->right){
           m[front->right] = front;
           q.push(front->right);
       }
       if(root->data==target){
           res=front;
       }
   }
   return res;
}

int solve(map<Node*,Node*> m,Node* root){
    queue<Node*> q;
    map<Node*,bool> v;
    q.push(root);
    v[root]=1;

    int time=0;
    while(!q.empty()){
        bool flag=0;
        int size= q.size();
        for(int i=0; i<size; i++){
            Node* front= q.front();
            q.pop();
            if(front->left && !v[front->left]){
                q.push(front->left);
                v[front->left]=1;
                flag=1;
            }
            if(front->right && !v[front->right]){
                q.push(front->right);
                v[front->right]=1;
                flag=1;
            }       
            if(m[front] && !v[m[front]]){
                q.push(m[front]);
                v[m[front]]=1;
                flag=1;
            }     
        }
        if(flag==1){
            time++;
        }
    }
    return time;
}

int minTime(Node* root, int target){
    map<Node *, Node *> m;
    Node* Tar=createMap(m,root,target);
    return solve(m,Tar);
}
