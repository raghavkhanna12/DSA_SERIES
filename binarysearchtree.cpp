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
Node* minvalue(Node* root){
    Node* temp=root;
    while(temp!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* DeleteFromBST(Node* root,int x){
    
    if(root==NULL){
        return root;
    }
    if(root->data==x){
         if(root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
         }

         if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete(root);
            return temp;
         }
         if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete(root);
            return temp;
         }

         if(root->left!=NULL && root->right!=NULL){
            int mini=minvalue(root->right)->data;
            root->data=mini;
            DeleteFromBST(root->right,x);
         }
    }

    if(x>root->data){
        root->right=DeleteFromBST(root->right,x);
    }
    else{
        root->left=DeleteFromBST(root->left,x);
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
        cout<<endl;
        DeleteFromBST(root,5);
        inorder(root);
    }