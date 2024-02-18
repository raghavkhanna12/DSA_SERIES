#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->next=NULL;
        this->data=data;
    }
};

void insert(Node* head,int position,int d){
    Node* temp=head;
    for(int i=0;i<position-1;i++){
          temp=temp->next;
    }
    Node* curr=new Node(d);
    curr->next=temp->next;
    temp->next=curr;

}
void deletenode(Node* head,int position){
    Node* temp=head;
    for(int i=0;i<position-1;i++){
          temp=temp->next;
    }
    Node* curr=temp->next;
    temp->next=curr->next;
    curr->next=NULL;
    delete(curr);
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
       
    }
}

int main(){
    Node* head=new Node(10);
    insert(head,1,20);
    insert(head,2,30);
    deletenode(head,1);
    print(head);

}
