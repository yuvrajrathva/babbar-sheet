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
    Node *revListInGroupOfGivenSize(Node *head, int k)
    {
        if (!head || k == 1 || !head->next)
        {
            return head;
        }

        struct Node *dummy = new Node(-1);
        dummy->next = head;
        struct Node *prev = dummy, *curr = dummy, *next = dummy;

        int total_length = 0;
        while (curr)
        {
            curr = curr->next;
            total_length++;
        }

        while (prev && prev->next && prev->next->next)
        {
            curr = prev->next;
            next = curr->next;

            int loop = total_length > k ? k : total_length - 1;
            for (int i = 1; i < loop; i++)
            {
                curr->next = next->next;

                if (next->next != NULL)
                {
                    next->next->prev = next->prev; //
                }

                next->next = prev->next;
                next->prev = prev; //

                prev->next = next;
                curr->prev = next; //

                next = curr->next;
            }

            prev = curr;
            total_length -= k;
        }

        return dummy->next;
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
    struct Node *ans = sol.revListInGroupOfGivenSize(head, k);
    print(ans);
    return 0;
}