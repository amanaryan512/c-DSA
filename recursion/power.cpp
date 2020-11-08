#include<iostream>
using namespace std;

int pow(int x,int n){
    //base case
    if(n==0){
        return 1;
    }
    //recursive case
    int smallOutput=pow(x,n-1);

    //calculation
    return x*smallOutput;
}

int main(){
    cout<<pow(5,3); 



    return 0;
}