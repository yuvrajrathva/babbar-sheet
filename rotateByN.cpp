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

class Solution
{
public:
    struct Node *rotateByN(Node *head, int k)
    {
        if (head == NULL && head->next == NULL)
        {
            return head;
        }

        struct Node *temp = head;
        struct Node *old_end = NULL;
        struct Node *old_start = head;
        struct Node *new_end = NULL;

        while (temp->next)
        {
            temp = temp->next;
        }

        old_end = temp;
        temp = old_start;

        while (k > 0)
        {
            k--;
            new_end = temp;
            temp = temp->next;
        }

        temp->prev = NULL;
        head = temp;
        new_end->next = NULL;
        old_start->prev = old_end;
        old_end->next = old_start;
        return head;
    }
};

int main()
{
    int n;
    cin >> n;
    int input;
    struct Node *temp = NULL;
    struct Node *head = NULL;
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

    int k;
    cin >> k;

    Solution sol;
    struct Node *ans = sol.rotateByN(head, k);

    print(ans);
    return 0;
}