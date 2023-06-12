#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
    {
        return;
    }
    Node *walk = head;
    for (int i = 1; i < position; i++)
    {
        walk = walk->next;
    }
    tail->next = walk;
}

class Solution
{
public:
    // Function to check if the linked list has a loop.
    void removeLoop(Node *head)
    {
        struct Node *temp = head;
        struct Node *prev;
        unordered_set<Node *> s;

        while (temp)
        {
            if (s.find(temp->next) != s.end())
            {
                if (temp == head) 
                {
                    prev->next = NULL;
                }
                else
                {
                    temp->next = NULL;
                }
                break;
            }

            s.insert(temp->next);
            prev = temp;
            temp = temp->next;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    struct Node *head = NULL;
    struct Node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        int input;
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

    int pos;
    cin >> pos;
    loopHere(head, temp, pos);

    Solution sol;
    sol.removeLoop(head);

    struct Node *print = head;
    while (print)
    {
        cout << print->data << " ";
        print = print->next;
    }

    return 0;
}