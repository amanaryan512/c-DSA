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
    if(head==NULL)
    return false;
    if(head->data==data)
    return true;

    return search(head->next,data); // call for the rest of the elements.
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