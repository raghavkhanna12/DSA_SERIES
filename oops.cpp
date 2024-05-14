#include<bits/stdc++.h>
using namespace std;

// class base1{
//     public:
//     int d;

//     void func1(int d){
//         cout<<"you enter "<<d<<endl;
//     }
// };
// class base2{
//     public:
//     int e;

//     void func3(int d){
//         cout<<"you enter "<<d<<endl;
//     }
// };

// class derived:public base1,base2{

//      public:
//      void func2(){
//         cout<<"you enter "<<d<<endl;
//      }
// };

class hello{
    private:
    int d;

    public:
    hello(){
        d=10;
    }

    friend class f;
};

 class f{
      public:
      void display(hello &p){
        cout<<p.d<<endl;
      }
};


int main(){
//     base1 b;
//     derived d;

//    // b.func1(10);
//     d.func1(10);
hello g;
f h;
h.display(g);

}