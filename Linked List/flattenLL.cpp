#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *down;
};
Node *head = NULL;

Node *push(Node *head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->right = NULL;
    temp->down = head;

    head = temp;

    return head;
}

void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->down;
    }
    cout << endl;
}

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }

    else if (b == NULL)
    {
        return a;
    }

    Node *result;
    if (a->data < b->data)
    {
        result = a;
        result->down = merge(a->down, b);
    }
    else
    {
        result = b;
        result->down = merge(a, b->down);
    }

    result->right = NULL;
    return result;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->right == NULL) // handling basic conditions
    {
        return root;
    }

    root->right = flatten(root->right); // recursively flattening right side of LLus

    root = merge(root, root->right);

    return root;
}

int main()
{
    head = push(head, 30);
    head = push(head, 20);
    head = push(head, 10);
    head = push(head, 1);

    head->right = push(head->right, 20);
    head->right = push(head->right, 2);

    head->right->right = push(head->right->right, 50);
    head->right->right = push(head->right->right, 22);
    head->right->right = push(head->right->right, 19);

    head->right->right->right = push(head->right->right->right, 45);
    head->right->right->right = push(head->right->right->right, 40);
    head->right->right->right = push(head->right->right->right, 35);
    head->right->right->right = push(head->right->right->right, 20);

    // Function call
    head = flatten(head);
    printList();
    return 0;
}