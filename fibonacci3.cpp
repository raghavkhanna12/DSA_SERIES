#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int prev1=0;
    int prev2=1;
    for(int i=0;i<n;i++){
        int current=prev1+prev2;
        prev1=prev2;
        prev2=current;
    }
    cout<<prev1<<endl;
}