//{ Driver Code Starts
#include <iostream>

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
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

/* Driver program to test above function*/
int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    Node *head1 = inputList(n1);
    Node *head2 = inputList(n2);
    Node *common = inputList(n3);

    Node *temp = head1;
    while (temp != NULL && temp->next != NULL)
        temp = temp->next;
    if (temp != NULL)
        temp->next = common;

    temp = head2;
    while (temp != NULL && temp->next != NULL)
        temp = temp->next;
    if (temp != NULL)
        temp->next = common;

    cout << intersectPoint(head1, head2) << endl;
    return 0;
}


// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    unordered_set<Node*> s;

    while(temp1->next){
        s.insert(temp1->next);
        temp1 = temp1->next;
    }

    while(temp2->next){
        if(s.find(temp2->next)!=s.end()){
            return temp2->next->data;
        }
        temp2 = temp2->next;
    }

    return -1;
}
