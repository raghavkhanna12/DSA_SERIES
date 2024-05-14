#include<bits/stdc++.h>
using namespace std;

// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int data){
//        this->data=data;
//        this->left=NULL;
//        this->right=NULL;
//     }

//     Node* insert(Node* root,int data){
//         if(root==NULL){
//             Node* root=new Node(data);
//             return root;
//         }

//         if(data>root->data){
//             root->right=insert(root->right,data);

//         }

//         if(data<root->data){
//             root->left=insert(root->left,data);
//         }
//     }

//     Node* minvalue(Node* root){
//         Node* temp=root;
//         while(temp!=NULL){
//             temp=temp->left;
//         }
//         return temp;
//     }

//     Node* deletenode(Node* root,int x){
//         if(root==NULL){
//             return root;
//         }

//         if(root->data=x){
//             if(root->left==NULL && root->right==NULL){
//                 delete(root);
//                 return NULL;
//             }

//             if(root->left!=NULL && root->right==NULL){
//                   Node* temp=root->left;
//                   delete(root);
//                   return temp;
//             }
//             if(root->left==NULL && root->right!=NULL){
//                   Node* temp=root->right;
//                   delete(root);
//                   return temp;
//             }
//             if(root->left!=NULL && root->right!=NULL){
//                   int mini=minvalue(root->right)->data;
//                   root->data=mini;
//                   root->right=deletenode(root->right,mini);
//                   return root;
//             }
//         }

//         if(data>root->data){
//             root->right=deletenode(root->right,data);
//         }
//         if(x<root->data){
//             root->left=deletenode(root->left,data)
//         }
//     }
// };






























int main(){
    // int n,e;
    // cin>>e;
    // cin>>n;
    // int arr[n];
    
    // set<int,greater<int>>s;

    // for(int i=0;i<n;i++){
    //      cin>>arr[i];
    //      s.insert(arr[i]);
    // }
    // int count=0;
    
    // for(auto i=s.begin();i!=s.end();i++){
    //     if(e>=*i && e>0){
    //         e=e-*i;
    //         count++;
    //         if(e>0){
    //             e=e-*i;
    //             count++;
    //         }
    //     }
    // }
    // cout<<count<<endl;

    cout<<7/10<<endl;

}



    // sort(arr,arr+n,greater<int>());
    // int d;
    // int count=0;
    // for(int i=0;i<n;i++){
    //     if(e>=arr[i] && e>0){
    //       e=e-arr[i];
    //       count++;
    //       if(e>0){
    //       e=e-arr[i];
    //       count++;
    //       }
    //             }
    // }
    // cout<<count<<endl;
