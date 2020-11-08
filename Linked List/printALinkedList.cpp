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
void print(Node *head){ // here i have a new value of head because of pass by value.
	Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next; // move forward
	}
	cout<<endl;
}


/*void print(Node *&head){  //here it have the reference of the main head
	while(head!=NULL){
		cout<<head->data<<"-> ";
		head=head->next;
	}
}
*/

int main(){
	Node n1(1);
	Node *head=&n1;

	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);

	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;

	print(head); //pass by value not by reference.
	print(head);


	return 0;
}