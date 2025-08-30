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

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool searchInBST(Node *root, int x) {
    if (root == NULL)
    {
        return false;
    }
    if(root->data == x){
        return true;
    }
    if (x < (root->data))
    {
        return searchInBST(root->left,x);
    }
    else
    {
        return searchInBST(root->right,x);
    }
}

Node *searchBST(Node *root,int x){
    Node *temp= root;
    while(temp){
        if (temp->data=x){
            return temp;
        }
        if(temp->data < x){
            temp= temp->right;
        }
        else{
            temp= temp->left;
        }
    }
    return NULL;
}

Node *minval(Node *root){
    Node *temp= root;
    while(temp->left!=NULL){
        temp= temp->left;
    }
    return temp;
}

Node *maxval(Node *root){
    Node *temp= root;
    while(temp->right!=NULL){
        temp= temp->right;
    }
    return temp;
}

Node *findp(Node* curr){
    Node *pred=curr->left;
    while(pred->right!=NULL){
        pred=pred->right;
    }
    return pred;
}

Node *finds(Node* curr){
    Node *succ=curr->right;
    while(succ->left!=NULL){
        succ=succ->left;
    }
    return succ;
}

Node *deleteNode(Node *root, int x){
    if (root == NULL)
    {
        return root;
    }
    if(root->data == x){
        if(root->left==NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left && root->right){
            int mini= minval(root->right) ->data;
            root->data= mini;
            root->right=deleteNode(root->right,mini);
            return root;
        }
        else if(root->left){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node *temp = root->right;
            delete root;
            return temp;
        }
    }
    else if (x < (root->data))
    {
        root->left = deleteNode(root->left,x);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right,x);
        return root;
    }
}

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data < (root->data))
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

Node *takeInput(Node *root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root=insertIntoBST(root, data);
        cin >> data;
    }
    return root;
}

int main()
{
    Node *root = NULL;

    cout << "enter data to create BST : " << endl;
    
    root=takeInput(root);

    cout<< "printing BST:"<<endl;

    postorder(root);
    // 10 8 21 7 27 5 4 3 -1
    return 0;
}  

