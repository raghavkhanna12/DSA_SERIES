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

Node* buildtree(Node* root){
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }

    root->left=buildtree(root->left);
    root->right=buildtree(root->right);

    return root;
}