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

int middle(Node* head){
    Node* fast=head;
    Node* slow=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;

}

bool circular(Node* &head){
   Node*temp=head;
   while(temp!=NULL){
    temp=temp->next;
    if(temp==head){
        return true;
    }
   }
   return false;
}

void reverse(Node* &head){
    Node* temp=head;
    Node* prev=NULL;
    Node* curr=NULL;
    while(temp!=NULL){
        curr=temp->next;  
        temp->next=prev;
        prev=temp;
        temp=curr;
  }
      head=prev;

}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;  
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(10);
    insert(head,1,20);
    insert(head,2,30);
   // deletenode(head,1);
    reverse(head);
    print(head);
    cout<<middle(head)<<endl;
    if(circular(head)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

}
