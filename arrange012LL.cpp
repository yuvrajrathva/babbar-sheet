#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data); // new node created with data = data
    temp->next = head;           // pointing its next to head of current linked list
    head = temp;                 // assign head to this temp (new Node become a new head)
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *arrange(Node *head)
{
    if(!head || !head->next){
        return head;
    }

    Node *temp = head;
    Node *end = head;
    Node* prev = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    end = temp;
    temp = head->next;
    while (temp)
    {
        if(temp->data == 0){
            prev->next = temp->next;
            temp->next = head;
            head = temp;
            temp = prev->next;
        }else if(temp->data ==2 && temp!=end){
            prev->next = temp->next;
            temp->next = NULL;
            end->next = temp;
            end = temp;
            temp = prev->next;
        }else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    int n;
    cin >> n;
    int input;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (i == 0)
        {
            Node *temp = new Node(input);
            head = temp;
        }
        else
        {
            insertAtHead(head, input);
        }
    }

    Node *ans = arrange(head);

    print(ans);
    return 0;
}