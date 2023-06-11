#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(struct node *node)
{

    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {   
        if (!head || k == 1)
        {
            return head;
        }
        
        struct node *dummy = new node(-1);
        dummy->next = head;
        struct node *prev = dummy, *curr = dummy, *next = dummy;

        int total_length = 0;
        while (curr)
        {
            curr = curr->next;
            total_length++;
        }

        while (next)
        {
            curr = prev->next;
            next = curr->next;

            int loop = total_length > k ? k : total_length - 1;
            for (int i = 1; i < loop; i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            total_length-=k;
        }
        return dummy->next;
    }
};

int main()
{
    struct node *head = NULL;
    struct node *temp = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        if (i == 0)
        {
            head = new node(value);
            temp = head;
        }
        else
        {
            temp->next = new node(value);
            temp = temp->next;
        }
    }

    int k;
    cin >> k;

    Solution sol;
    head = sol.reverse(head, k);
    print(head);

    return 0;
}