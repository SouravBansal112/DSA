#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int height(node* root){
    if(root==NULL){
        return 0;
    }

    return max(height(root->right),height(root->left)) +1;
}

pair<bool, int> isBalancedFast(Node* root) {
            // base case
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    pair<int,int> left = isBalancedFast(root->left);
    pair<int,int> right = isBalancedFast(root->right);
    
    
    bool leftAns = left.first;
    bool rightAns = right.first;
    
    bool diff = abs (left.second - right.second ) <=1;
    
    pair<bool,int> ans;
    ans.second = max(left.second, right.second) + 1;
    
    if(leftAns && rightAns && diff) {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool isBalanced(Node *root)
{
    return isBalancedFast(root).first;
}

bool isIdentical(Node *r1, Node *r2)

{
    if(r1 == NULL && r2 == NULL) {
        return true;
    }
    bool value = r1->data == r2->data;
    if (value && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right)){
        return true;
    }
    else{
        return false;
    }   
}  

int sumTree(node* root,bool& cond){

    if(root==NULL){
        return 0;
    }

    if(root->left==NULL && root->right==NULL){
        cond=true;
        return root->data;
    }
    int val=root->data;
    int left=sumTree(root->left,cond);
    int right=sumTree(root->right,cond);
    if(left+right!=val){
        cond=false;
    }
    return left+right+val;
}