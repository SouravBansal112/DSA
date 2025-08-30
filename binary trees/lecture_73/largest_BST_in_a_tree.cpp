#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct info{
    public:
    int min;
    int max;
    bool isBST;
    int size;
};

info solve(TreeNode* root, int &ans) {
    if (root == NULL) {
        return {INT_MAX, INT_MIN, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    if (left.isBST && right.isBST && root->data > left.max && root->data < right.min) {
        int currSize = left.size + right.size + 1;
        ans = max(ans, currSize);

        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);

        return {currMin, currMax, true, currSize};
    }

    // Not a BST
    return {INT_MIN, INT_MAX, false, 0};
}


int largestBST(TreeNode * root){
    int maxsize=0;
    info temp= solve(root,maxsize);
    return maxsize;
}
