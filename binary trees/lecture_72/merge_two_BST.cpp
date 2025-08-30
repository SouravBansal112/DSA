#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void convertintosorteddll(TreeNode* root, TreeNode* &head){
    if(root == NULL){
        return;
    }
    convertintosorteddll(root->right,head);
    root->right = head;
    if (head != NULL) {
        head->left = root;
    }
    head = root;
    convertintosorteddll(root->left,head);   
}

TreeNode* mergeDll(TreeNode* head1,TreeNode* head2){
    TreeNode* head=NULL;
    TreeNode* tail=NULL;
    while(head1!=NULL && head2!= NULL){
        if(head1->data < head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;       
    }
    return head;
}

int cntNodes(TreeNode* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->right;
    }
    return cnt;
}

TreeNode* createTree(TreeNode* &head,int n){
    if(n<=0){
        return NULL;
    }
    TreeNode* left= createTree(head,n/2);
    TreeNode* root=head;
    root->left=left;
    head=head->right;
    root->right =createTree(head,n-n/2-1);
    return root;
}

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    TreeNode * head1=NULL;
    TreeNode * head2=NULL;
    convertintosorteddll(root1, head1);
    convertintosorteddll(root2, head2);
    TreeNode * head=mergeDll(head1, head2);
    int n = cntNodes(head);
    TreeNode* root= createTree(head, n);
    vector<int> v;
    inorderTraversal(root,v);
    return v;
}