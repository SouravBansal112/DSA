#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

node* solve(vector<int> &inorder,vector<int> &preorder,int &index,int s,int e,int size){
    if(index>=size || s>e){
        return NULL;
    }
    node *root=new node(preorder[index++]);
    int pos=-1;
    for(int i =0 ; i<size ; i++){
        if(inorder[i]==root->data){
            pos=i;
            break;
        }
    }
    root->left = solve(inorder,preorder,index,s,pos-1,size);
    root->right = solve(inorder,preorder,index,pos+1,e,size);
    return root;
}
node* buildTree(vector<int> &inorder, vector<int> &preorder){
    int index=0;
    int s= 0;
    int e= inorder.size()-1;
    node* root=solve(inorder, preorder, index, s, e, inorder.size());
    return root;
}

/*Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays inorder[] and postorder[] respectively. The task is to construct a unique binary tree from these traversals and return its root.
Driver code will print the preorder traversal of the constructed tree.

Note: The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is also found in the inorder traversal.*/
node* solve2(vector<int> &inorder,vector<int> &postorder,int &index,int s,int e,int size){
    if(/*index<0 ||*/ s>e){
        return NULL;
    }
    node *root=new node(postorder[index--]);
    int pos=-1;
    for(int i =0 ; i<size ; i++){
        if(inorder[i]==root->data){
            pos=i;
            break;
        }
    }
    root->right = solve2(inorder,postorder,index,pos+1,e,size);
    root->left = solve2(inorder,postorder,index,s,pos-1,size);
    return root;
}
node* buildTree(vector<int> &inorder, vector<int> &postorder){
    int index=inorder.size()-1;
    int s= 0;
    int e= inorder.size()-1;
    node* root=solve2(inorder, postorder, index, s, e, inorder.size());
    return root;
}

