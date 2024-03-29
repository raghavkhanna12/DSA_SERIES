#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int result=binarysearch(arr,n,key);
    cout<<"The index is : "<<result<<endl;
}