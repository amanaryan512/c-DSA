#include<iostream>
using namespace std;

void print(int n){ //ascending order
    
    //base case
    if(n==0){
        return ;
    }

    //recussive case
    print(n-1);  //1 2 3 .... n-1
    cout<<n<<endl;
    return;
}

void print2(int n){ // descending order
    if(n==0){
        return;
    }
    cout<<n<<endl;

    print2(n-1);
    return;
}

int main(){
    print2(5);



    return 0;
}