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

Node* LevelOrderTraversal(Node* root,int data){
    root=new Node(data);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* frontNode= q.front();
        q.pop();
        cout<<frontNode->data<<" ";
        if(frontNode->left){
            q.push(frontNode->left);
        }
        if(frontNode->right){
            q.push(frontNode->right);
        }
    }
    return root;

}