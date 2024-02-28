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

void heapify(int arr[],int n,int i){
int largest=i;
int left=2*i;
int right=2*i+1;

if(left<=n && arr[largest]<arr[left]){
    largest=left;
}

if(right<=n && arr[largest]<arr[right]){
    largest=right;
}

if(largest!=i){
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
}
}



void sortheap(int arr[],int n){
     int size=n;
     while(size>1){
    swap(arr[size],arr[1]);
    size--;
    heapify(arr,size,1);
     }
}
int main(){
    heap h;
    
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.deletefromheap();

    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sortheap(arr,n);
     for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
   // h.print();
}