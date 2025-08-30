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

vector<int> zigZagTraversal(node* root) {
    vector<int> result;
    if(root==NULL){
        return result;
    }
    queue<node *> q;
    q.push(root);
    bool leftToRight=true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {   
            node* element= q.front();
            q.pop();
            int index=leftToRight? i : size-1-i;
            ans[index]=element->data;

            if(element->left){
                q.push(element->left);
            }
            if(element->right){
                q.push(element->right);
            }
        }
        leftToRight=!leftToRight;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}

void trav(node *root,vector<int> &ans)
{
    if (root == NULL)
    {
        return; 
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    trav(root->left,ans);
    trav(root->right,ans);
}

void Lefttrav(node *root,vector<int> &ans)
{
    if ((root == NULL) || (root->left==NULL && root->right==NULL))
    {
        return; 
    }
    ans.push_back(root->data);
    if(root->left){
        Lefttrav(root->left,ans);
    }
    else{
        Lefttrav(root->right,ans);
    }
}

void Righttrav(node *root,vector<int> &ans)
{
    if ((root == NULL) || (root->left==NULL && root->right==NULL))
    {
        return; 
    }
    if(root->right){
        Righttrav(root->right,ans);
    }
    else{
        Righttrav(root->left,ans);
    }
    
    ans.push_back(root->data);    
}
   
vector<int> boundaryTraversal(node *root) {
    
    vector<int> ans;

    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);

    Lefttrav(root->left,ans);
    trav(root->left,ans);
    trav(root->right,ans);
    Righttrav(root->right,ans);
    return ans;
        
}

vector<int> verticalOrder(node *root)
{
    map<int, map<int,vector<int> > > nodes;
    queue< pair<node*, pair<int,int> > > q;
    vector<int> ans;
    
    if(root == NULL)
        return ans;
        
    q.push(make_pair(root, make_pair(0,0)));
    
    while(!q.empty()) {
        pair<node*, pair<int,int> > temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        
        nodes[hd][lvl].push_back(frontNode->data);
        
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
            
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }
    
    for(auto i: nodes) {
        
        for(auto j:i.second) {
            
            for(auto k:j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

void solveLeft(node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solveLeft(root->left, ans, level+1);
    solveLeft(root->right, ans, level+1);
}
vector<int> leftView(node *root)
{
   vector<int> ans;
   solveLeft(root, ans, 0);
   return ans;
}

 vector<int> topView(node *root)
{
    vector<int> ans;
    if(root == NULL) 
    {
        return ans;
    }

    map<int,int> topNode;
    queue<pair<node*, int> > q;

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second;
        
        //if one value is present for a HD, then do nothing
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode -> data;
            
        if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }

    for(auto i:topNode) 
    {
        ans.push_back(i.second);
    }
    return ans;
}

vector <int> bottomView(node *root) {
        vector<int> ans;
    if(root == NULL) 
    {
        return ans;
    }

    map<int,int> topNode;
    queue<pair<node*, int> > q;

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second;
        
        topNode[hd] = frontNode -> data;
            
        if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }

    for(auto i:topNode) 
    {
        ans.push_back(i.second);
    }
    return ans;
    }

void solveRight(node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->right, ans, level+1);    
    solve(root->left, ans, level+1);
    
}
vector<int> rightView(node *root)
{
    vector<int> ans;
    solveRight(root, ans, 0);
    return ans;
}



