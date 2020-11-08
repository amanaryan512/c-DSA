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
   Node* insertAtithPosition(Node *head,int i, int data){
       if(i<0){
           return head;
       }
       if(i==0)   //special case
       {
           Node *n=new Node(data);
           n->next=head;
           head=n;
           return head;
       }
       Node* copyHead=head;
       int count=1;
       while (count<=i-1 && head)
       {
           head=head->next;
           count++;
       }
       if(head){
           Node *n=new Node(data);
           n->next=head->next;
           head->next=n;
           return copyHead;

       }
       return copyHead;
   }

int main(){
    Node* head=takeinput();
    int i,data;
    cin>>i>>data;
    head=insertAtithPosition(head,i,data);
    print(head);
    return 0;
}