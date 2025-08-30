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


//validating BST
bool isBST(Node* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data <= max && root->data >= min ){
        bool left= isBST(root->left,min,root->data);
        bool right= isBST(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}

//Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’ smallest element in the given BST( binary search tree).
int ksmall(Node *root,int k, int &count){
    if(root==NULL){
        return -1;
    }
    int left=ksmall(root->left,k,count);
    if(left!=-1){
        return left;    }
    count++;
    if(k==count){
        return root->data;
    }
    return ksmall(root->right,k,count);
}

//find predecessor and successor
pair<int, int> predecessorSuccessor(Node *root, int key)
{
    Node* temp=root;
    int pre=-1;
    int suc= -1;
    while(temp!=NULL && temp->data!=key ){
        if(temp->data > key){
            suc= temp->data;
            temp=temp->left;

        }
        else{
            pre=temp->data;
            temp=temp->right;
        }
    }
    if(temp==NULL){
        return make_pair(pre,suc);
    }
    Node* left=temp->left;
    while(left!=NULL){
        pre=left->data;
        left=left->right;
    }
    Node* right= temp->right;
    while(right!=NULL){
        suc=right->data;
        right=right->left;
    }
    return make_pair(pre,suc);
}

