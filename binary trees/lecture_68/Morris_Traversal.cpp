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

//MORRIS TRAVERSAL

Node *find(Node* curr){
    Node *pred=curr->left;
    while(pred->right!=NULL && pred->right!=curr){
        pred=pred->right;
    }
    return pred;
}

void MorrisTraversal(Node *root) {
    Node *curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            Node *pred= find(curr);
            if(pred->right==NULL){
                pred->right=curr;
                curr=curr->left;
            }
            else{
                pred->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            } 
        }
    }    
}

/*Given the root of a binary tree, flatten the tree into a "Linked list":

The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.*/

void flatten(Node *root) {
    Node *curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            curr=curr->right;
        }
        else{
            Node *pred= find(curr);
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
            curr=curr->right;  
        }
    }    
}

