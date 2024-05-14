#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insert(Node* head,int data,int position){
    if(head==NULL){
        return ;
    }
        Node* temp=head;
    for(int i=0;i<position-1;i++){
            temp=temp->next;
    }
     Node* curr= new Node(data);
     curr->next=temp->next;
     temp->next=curr;

}

void deleteNode(Node* head,int position){
       
       if(head==NULL){
        return;
       }

       Node* temp=head;
       for(int i=0;i<position-1;i++){
          temp=temp->next;
       }
        Node* curr=temp->next;
        temp->next=curr->next;
        delete(curr);
}