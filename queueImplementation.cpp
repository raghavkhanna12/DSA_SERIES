#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int size;
    int qfront;
    int rear;
    int *arr;

    Queue(int size){
        this->size=size;
        qfront=-1;
        rear=-1;
        arr= new int[size];
    }

    bool isempty(){
        if(rear==size){
            return false;
     }
     else{
        return true;
     }
 }

 void enqueue(int element){
    if(rear==size){
        cout<<"queue is full"<<endl;
    }
    else{
        arr[rear]=element;
        rear++;
    }
 }

   int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        else
        {	int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
         return ans;
        }
    }
 int peek(){
    if(rear==qfront){
       return -1;
    }
    else{
        return arr[qfront];
    }
 }

};