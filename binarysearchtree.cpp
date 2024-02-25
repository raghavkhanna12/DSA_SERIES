#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* InsertIntoBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data>root->data){
        root->right=InsertIntoBST(root->right,data);
    }
    else {
        root->left=InsertIntoBST(root->left,data);
    }
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }

    int main(){
        Node* root= new Node(10);
        InsertIntoBST(root,30);
        InsertIntoBST(root,5);
        InsertIntoBST(root,50);
        inorder(root);
    }