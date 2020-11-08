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
bool search(Node *head, int data){
    Node *temp=head;
    while(temp!=NULL){ // iterating over the linked list
    if(temp->data==data)
    {
     return true;
    }
    temp=temp->next;
    }
    return false;
    
    }

int main(){
    Node* head=takeinput();
    int data;
    cin>>data;
    
    if(search(head,data)){
    cout<<"found";
    }
    else{
    cout<<"not found";
    }
	return 0;
}