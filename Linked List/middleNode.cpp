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
Node* middleNode(Node* head){
    Node *slow=head;
    Node *fast=head->next;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast){
        return slow->next;
    }
    return slow;
}

int main()
{
    Node* head=takeInput();
    Node *middle=middleNode(head);
    cout<<"Midde node is"<<middle->data;


    return 0;
}