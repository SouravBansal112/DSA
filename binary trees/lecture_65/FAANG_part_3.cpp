#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.
void sumOfLongest(node *root, pair<int, int> s, pair<int, int> &ans)
{
    if (root == NULL)
    {
        if (s.second > ans.second)
        {
            ans = s;
        }
        if (s.second == ans.second)
        {
            ans.first = max(ans.first, s.first);
        }
        return;
    }
    s.first += root->data;
    s.second++;
    sumOfLongest(root->left, s, ans);
    sumOfLongest(root->right, s, ans);
}
int sumOfLongRootToLeafPath(node *root)
{
    pair<int, int> s = make_pair(0, 0);
    pair<int, int> ans = make_pair(0, 0);
    sumOfLongest(root, s, ans);
    return ans.first;
}

/*Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.*/
node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *leftAns = lca(root->left, n1, n2);
    node *rightAns = lca(root->right, n1, n2);
    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns == NULL && rightAns == NULL)
    {
        return NULL;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
}

// Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).
void SumKSolve(node *root, int k, vector<int> &path, int &count)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    SumKSolve(root->left, k, path, count);
    SumKSolve(root->right, k, path, count);
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}
int sumK(node *root, int k)
{
    vector<int> path;
    int count = 0;
    SumKSolve(root, k, path, count);
    return count;
}

// Given a binary tree of size  n, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
int kans(Node *root, int &k, int node)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == node)
    {
        return root->data;
    }

    int leftAns = kans(root->left, k, node);
    int rightAns = kans(root->right, k, node);

    if (leftAns == -1 && rightAns != -1)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root->data;
        }
        return rightAns;
    }
    if (leftAns != -1 && rightAns == -1)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root->data;
        }
        return leftAns;
    }
    if (leftAns == -1 && rightAns == -1)
    {
        return -1;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    int ans = kans(root, k, node);
    if (ans == node)
    {
        return -1;
    }
    return ans;
}

/*Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.*/
pair<int, int> altSum(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = altSum(root->left);
    pair<int, int> right = altSum(root->right);
    pair<int, int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);
    return res;
}
int getMaxSum(node *root)
{
    pair<int, int> res = altSum(root);
    return max(res.first, res.second);
}
