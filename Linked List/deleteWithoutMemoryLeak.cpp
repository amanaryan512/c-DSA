#include<iostream>
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
void print(Node*head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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
   Node* deleteAtithPosition(Node *head,int i){
       if(i<0){
           return head;
       }
       if(i==0 && head)   //special case
       {
           Node* newHead=head->next;
           head->next=NULL; //isolate node
           delete head;  //delete means deallocate the memory
           return newHead;
       }
       Node* current=head;
       int count=1;
       while(count<=i-1 &&current!=NULL){
           current=current->next;
           count++;
       }
       if(current && current->next)//current->next is for extreme i(for i=length-1)
       {
           Node* temp=current->next;
           current->next=current->next->next;
           temp->next=NULL;
           delete temp;
           return head;
       }
       return head;

   }

int main(){
    Node* head=takeinput();
    int i;
    cin>>i;
    head=deleteAtithPosition(head,i);
    print(head);
    return 0;
}