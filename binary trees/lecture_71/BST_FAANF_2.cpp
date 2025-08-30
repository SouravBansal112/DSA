#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

/*You have been given a Binary Search Tree and a target value. You need to find out whether there exists a pair of node values in the BST, such that their sum is equal to the target value.

A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes each store a value greater than all the values keys in the node's left subtree and less than those in its right subtree.*/
void inorder(Node* root,vector<int> &intrav)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left,intrav);
    intrav.push_back(root->data);
    inorder(root->right,intrav);
}
bool twoSumInBST(Node root, int target) {
	vector<int> intrav;
    inorder(root,intrav);
    int i=0;
    int j=intrav.size()-1;
    while(i<j){
        if(intrav[i] + intrav[j] == target){
            return true;
        }
        if(intrav[i] + intrav[j] > target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

/*You have been given a binary search tree of integers with ‘N’ nodes. Your task is to convert it into a balanced BST with the minimum height possible.

A binary search tree (BST) is a binary tree data structure that has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
A Balanced BST is defined as a BST, in which the height of two subtrees of every node differs no more than 1.*/
void inorder(Node* root,vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
Node* createTree(vector<int> v,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    Node* root= new Node(v[mid]);
    root->left =createTree(v,s,mid-1);
    root->right =createTree(v,mid+1,e);
    return root;
}
Node* balancedBst(Node* root) {
    vector<int> v;
    inorder(root,v);
    return createTree(v,0,v.size()-1);
}

/*You have been given an array/list 'PREORDER' representing the preorder traversal of a BST with 'N' nodes. All the elements in the given array have distinct values.

Your task is to construct a binary search tree that matches the given preorder traversal.

A binary search tree (BST) is a binary tree data structure that has the following properties:

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.*/
Node* solve(vector<int> &preorder,int min, int max,int &i){
    if(preorder.size() <= i){
        return NULL;
    }
    if(preorder[i] < min || preorder[i] > max ){
        return NULL;
    }
        Node* root= new Node(preorder[i++]);
        root->left = solve(preorder,min,root->data,i);
        root->right = solve(preorder,root->data, max,i);
    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);
}




