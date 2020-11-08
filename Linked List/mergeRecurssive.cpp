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
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        cin >> data;
    }
    return head;
}

Node *merge(Node *l1, Node *l2)
{
    //base class
    if (l1 == NULL)
        return l2;

    if (l2 == NULL)
        return l1;

    Node *finalHead = NULL;

    if (l1->data < l2->data)
    {
        finalHead = l1;
        finalHead->next = merge(l1->next, l2);
    }
    else
    {
        finalHead = l2;
        finalHead->next = merge(l1, l2->next);
    }
    return finalHead;
}

int main()
{
    Node *head1 = takeInput();
    Node *head2 = takeInput();

    Node *finalHead = merge(head1, head2);
    print(finalHead);
    return 0;
}
