#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;

    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void push(Node *head, int d)
{
    struct Node *temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }

    struct Node *end = new Node(d);
    end->prev = temp;
}

void print(Node *head)
{
    struct Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int n;
    cin >> n;
    int input;
    struct Node* temp = NULL;
    struct Node* head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (i == 0)
        {
            head = new Node(input);
            temp = head;
        }
        else
        {
            temp->next = new Node(input);
            temp = temp->next;
        }
    }

    print(head);
    return 0;
}