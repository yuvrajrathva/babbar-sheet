#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

void merge(int arr1[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l, arr2[h + 1];
    while (i <= mid and j <= h)
    {
        if (arr1[i] < arr1[j])
        {
            arr2[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr2[k] = arr1[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        arr2[k] = arr1[i];
        k++;
        i++;
    }
    while (j <= h)
    {
        arr2[k] = arr1[j];
        k++;
        j++;
    }
    for (int i = l; i <= h; i++)
    {
        arr1[i] = arr2[i];
    }
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

class Solution
{
public:
    Node *mergeSort(Node *head)
    {
        struct Node* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }

        
    }
};


void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    struct Node *a = NULL;
    long n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        push(&a, tmp);
    }
    Solution obj;
    a = obj.mergeSort(a);
    printList(a);
    return 0;
}
// } Driver Code Ends