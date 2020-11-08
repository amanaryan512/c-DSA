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
void printithNode(Node *head,int i){
    if(i<0){
        cout<<"-1"<<endl;
        return;
    }
    int count=1;
    while (count<=i && head)
    {
        head=head->next;
        count++;
    }
    if(head){
        cout<<head->data<<endl;
    }
        else
        {
            cout<<"-1";  
        }
        
    }
    
int main(){
    Node *head=takeinput();
    int n;
    cin>>n;
    printithNode(head,n);

    return 0;
}