#include<iostream>
using namespace std;

int fact(int n){
    //base case
    if(n==0)
    return 1;

    int smallAns=fact(n-1); //asumption recussive case
    int ans=n*smallAns; //calculation using small problm
    return ans;
}

int main()
{
    int n;
cin>>n;
int answer=fact(n);
cout<<answer<<endl;
    return 0;
}
