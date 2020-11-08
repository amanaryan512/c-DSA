#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

Node* takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;

    while(data!=-1){
        Node *n= new Node(data);
        if(head==NULL){
            head=n;
            tail=n;
        }
        else{
            tail->next=n;
            tail=n;
        }
        cin>>data;
    }
    return head;
}

Node* reverse(Node* head){
    Node* current=head;
    Node* previous=NULL;

    while(current!=NULL){

    Node* n=current->next;
    current->next=previous;
    previous=current;
    current=n;

    }
    return previous;
}

int main(){
Node* head=takeInput();
//print(head);
Node* newHead=reverse(head);
print(newHead);

    return 0;
}