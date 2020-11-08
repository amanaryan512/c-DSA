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
		cout<<temp->data<<"-> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

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
void length(Node *head){
    int count=0;
    Node *temp=head;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
        
    }
    cout<<"lenth of the Linked list is :"<<count<<endl;
    
}

int main(){
	Node *head=takeinput();
	//print(head);
	length(head);


	return 0;
}