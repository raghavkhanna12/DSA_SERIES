#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    int sum1=INT_MIN;
    int max=-1;
    int max1;
    for(int i=0;i<3;i++){
         int sum=0;
        for(int j=0;j<3;j++){
            sum+=arr[i][j];
        }
        if(sum1<sum){
            sum1=sum;
           max=i;
        }
}
   cout<<sum1<<" "<<max<<endl;
}