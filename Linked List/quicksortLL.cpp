#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void print(node *head)
{
    struct node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

struct node *getTail(struct node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

node *partition(node *head, node *end, node **new_head, node **new_end)
{
    struct node *pivot = end;
    struct node *curr = head, *tail = pivot, *prev = NULL;

    while (curr != pivot)
    {
        if (curr->data < pivot->data)
        {
            if (!*new_head)
            {
                *new_head = curr;
            }

            prev = curr;
            curr = curr->next;
        }
        else
        {
            struct node *temp = curr->next;
            if (prev)
                prev->next = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if (*new_head == NULL)
    {
        *new_head = pivot;
    }

    *new_end = tail;

    return pivot;
}

node *quickSortRecurr(node *head, node *end)
{
    if (!head || head == end)
    {
        return head;
    }

    struct node *new_head = NULL, *new_end = NULL;

    struct node *pivot = partition(head, end, &new_head, &new_end);

    if (new_head != pivot)
    {
        struct node *tmp = new_head;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        new_head = quickSortRecurr(new_head, pivot);

        tmp = getTail(new_head);
        tmp->next = pivot;
    }
    pivot->next = quickSortRecurr(pivot->next, new_end);

    return new_head;
}

void quickSort(struct node **headRef)
{
    *headRef = quickSortRecurr(*headRef, getTail(*headRef));
    return;
}

int main()
{
    int n, input;
    cin >> n;
    struct node *head = NULL, *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (i == 0)
        {
            head = new node(input);
            temp = head;
        }
        else
        {
            temp->next = new node(input);
            temp = temp->next;
        }
    }

    quickSort(&head);
    print(head);
    return 0;
}