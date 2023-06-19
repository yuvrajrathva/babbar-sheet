#include <bits/stdc++.h>
using namespace std;

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

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
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

class Solution
{
public:
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        reverse(first);
        reverse(second);

        Node *temp1 = first;
        Node *temp2 = second;
        Node *head = new Node((temp1->data + temp2->data) % 10);
        int carry = (temp1->data + temp2->data) / 10;
        Node *temp = head;

        temp1 = temp1->next;
        temp2 = temp2->next;

        while (temp1 || temp2)
        {
            if (!temp1)
            {
                temp->next = new Node((temp2->data + carry) % 10);
                temp = temp->next;
                carry = (temp2->data + carry) / 10;
                temp2 = temp2->next;
            }

            else if (!temp2)
            {
                temp->next = new Node((temp1->data + carry) % 10);
                temp = temp->next;
                carry = (temp1->data + carry) / 10;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = new Node((temp1->data + temp2->data + carry) % 10);
                temp = temp->next;
                carry = (temp1->data + temp2->data + carry) / 10;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }


        while(carry!=0){
            temp->next = new Node(carry % 10);
            carry = carry / 10;
            temp = temp->next;
        }

        reverse(head);
        return head;
    }
};

int main()
{
    int n;
    cin >> n;

    int input;
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> input;

        if (i == 0)
        {
            head = new Node(input);
            tail = head;
        }
        else
        {
            tail->next = new Node(input);
            tail = tail->next;
        }
    }

    int m;
    cin >> m;

    Node *head2 = NULL;
    Node *tail2 = NULL;
    for (int i = 0; i < m; i++)
    {
        cin >> input;

        if (i == 0)
        {
            head2 = new Node(input);
            tail2 = head2;
        }
        else
        {
            tail2->next = new Node(input);
            tail2 = tail2->next;
        }
    }

    Solution sol;
    Node *ans = sol.addTwoLists(head, head2);
    print(ans);
    return 0;
}