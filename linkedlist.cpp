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
    curr->next=temp;
    temp=curr;

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

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;

}
 Node* deleteMiddle(Node* head) {
      Node* slow=head;
      Node* fast=head;
      Node* prev=NULL;

      if(!head->next){
          return NULL;
      }
      while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
            
      }
      prev->next=slow->next;
            slow->next=NULL;
            delete(slow);
      return head;
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
bool isPalindrome(Node* head) {
        Node* temp=head;
        vector<int>v;
        vector<int>v1;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp=temp->next;
        }
        reverse(head);
        Node* temp1=head;
        while(temp1!=NULL){
            v1.push_back(temp1->data);
            temp1=temp1->next;
        }
        cout<<endl;
        for(int i=0;i<v.size();i++){
                if(v[i]!=v1[i]){
                   return false;
                }
        }
        return true;
      
    }
 Node *detectCycle(Node* head){
   
       Node* slow=head;
       Node* fast=head;

       while(fast!=NULL && fast->next!=NULL){
          fast=fast->next->next;
          slow=slow->next;
          if(fast==slow){
               slow=head;
               while(slow!=fast){
                   slow=slow->next;
                   fast=fast->next;
               }
               return slow;
          }
       }
       return NULL;
          }



int main(){
    Node* head=new Node(10);
    insert(head,1,20);
    insert(head,2,30);
    // deletenode(head,1);
    // reverse(head);
     print(head);
    // cout<<middle(head)<<endl;
    // if(circular(head)){
    //     cout<<"yes"<<endl;
    // }
    // else{
    //     cout<<"No"<<endl;
    // }
    // if(isPalindrome(head)){
    //     cout<<"yes"<<endl;
    // }
    // else{
    //     cout<<"no"<<endl;
    // }

}
