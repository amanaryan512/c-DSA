#include<iostream>
using namespace std;

int fib(int n){
    //base case(Two base cases)
    if(n==0)
    return 0;
    if(n==1)
    return 1;

    //recusive case
    int smallOuput1=fib(n-1);
    int smallOutput2=fib(n-2);

    return smallOuput1+smallOutput2;//STep 3
}

int main(){
cout<<fib(3);
    return 0;
}