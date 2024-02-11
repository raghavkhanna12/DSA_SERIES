#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int flag=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"found"<<endl;
            flag=1;
            break;
        }
    }
    if(flag=0){
        cout<<"Not found"<<endl;
    }


}