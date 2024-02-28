#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }

  void insert(int data){
    size=size+1;
    int index=size;
    arr[index]=data;
    while(index>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }
        else{
            return;
        }
    }
  }

  void deletefromheap(){
    if(size==0){
        cout<<"heap is empty"<<endl;
    }
    arr[1]=arr[size];
      size--;

      int i=1;
      while(i<size){
        int leftindex=2*i;
        int rightindex=2*i+1;

        if(leftindex<size && arr[i]<arr[leftindex]){
            swap(arr[leftindex],arr[i]);
            i=leftindex;
        }
        if(rightindex<size && arr[i]<arr[rightindex]){
            swap(arr[leftindex],arr[i]);
            i=rightindex;
        }
        else {
            return;
        }
      }
  }

  void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
  }

};

int main(){
    heap h;
    
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.deletefromheap();
    h.print();
}