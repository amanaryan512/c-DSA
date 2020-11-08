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

Node* removeFromEnd(Node *head,int k){
    Node* one=head;
    Node* two=head;

    while(k--) //k iteration of two
    {
        two=two->next;
    }
    if(two==NULL){ // if length of linked list=k =>delete the head node.
        return one->next;
    }
    while(two->next!=NULL){  //when two reaches the last node ,one will one node before the desired node.
        one=one->next;
        two=two->next;
    }

    //delete node
    one->next=one->next->next;
    return head;
}

int main(){
    Node* head=takeInput();
    int k;
    cin>>k;
    Node* newHead=removeFromEnd(head,k);
    print(newHead);


    return 0;
}
