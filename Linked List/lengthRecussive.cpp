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
Node* takeinput(){
	int data;
	cin>>data;
	Node *head=NULL; //LL is empty
	Node *tail=NULL; //LL is empty
	while(data!=-1){
		//creating a LL
		Node *n=new Node(data);

		//ist node
		if(head==NULL){
			head=n;
			tail=n;
		}
		else{
			tail->next=n; //Inserting at tail.
			tail=n;
		}
		cin>>data;
	}
	return head;
}
int length(Node* head){
    if(head==NULL)
    return 0;
    int smallAns=length(head->next);
    return 1+smallAns;
}

int main(){
    Node* head=takeinput();
    cout<<length(head);
	

	return 0;
}