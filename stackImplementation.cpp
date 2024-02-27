#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int * arr;
    int size;
    int top;
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int element){
          if(size-top>1){
             top++;
            arr[top]=element;
           
          }
          else{
            cout<<"stck is full"<<endl;
          }
    }

    void pop(){
        if(top>=0){
            top--;
            
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }

    int peek(){
        if(top==-1){
            cout<<"stck is empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }

    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }


};

int main(){
    Stack s(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.pop();
   cout<<s.peek()<<endl;


}