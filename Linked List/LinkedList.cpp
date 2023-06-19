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

void reverse(Node *&head)
{
    // Initialize current, previous and next pointers
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}

void deleteN(Node *&head, int position)
{
    Node *temp = head;
    Node *prev = head;
    
    for (int i = 0; i < position; i++)
    {
        if (i == 0 && position == 1)
        {
            head = head->next;
            free(temp);
        }
        else
        {
            if (i == position - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;

                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
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

Node* reverse_recursive(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* rest = reverse_recursive(head->next);

    head->next->next = head; // here head node pointed to right side and other pointed to left because they are reversed already. Like this head->box2<-box3<-box4
    head->next = NULL; // beacuse now this become last node

    return rest;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;

    insertAtHead(head, 12);
    insertAtHead(head, 20);
    insertAtHead(head, 40);
    print(head);
    cout << endl;

    reverse_recursive(head);
    print(head);
    cout << endl;

    deleteN(head, 2);
    print(head);
    return 0;
}