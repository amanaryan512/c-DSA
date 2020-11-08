#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;

	Node(int data){
		this->data=data;
		next=NULL;
	}
};

int main(){
//creating objects of Node class statically
	Node n1(1);
	Node n2(2);

	n1.next=&n2;

	cout<<n1.data<<" "<<n2.data<<endl;

	Node *Head=&n1;

	cout<<Head->data<<endl;  //(*Head).data

	//creating objects of Node class dynamically

	Node *n3=new Node(3);
	Node *n4=new Node(4);
	n3->next=n4;
	cout<<n3->data<<" "<<n4->data<<endl;



	 return 0;

}