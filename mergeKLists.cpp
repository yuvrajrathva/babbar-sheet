// C++ program to merge k sorted
// arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
	int data;
	Node* next;
};

/* Function to print nodes in
a given linked list */

// A Linked List node
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

Node *mergeKLists(Node *arr[], int K)
{
    Node *head = NULL;
    while (1)
    {
        int a = 0;
        int z;
        Node *curr;
        int min = INT_MAX;
        for (int i = 0; i < K; i++)
        {
            if (arr[i] != NULL)
            {
                a++;
                if (arr[i]->data < min)
                {
                    min = arr[i]->data;
                    z = i;
                }
            }
        }
        if (a != 0)
        {
            arr[z] = arr[z]->next;
            Node *temp = new Node(min);
            if (head == NULL)
            {
                head = temp;
                curr = temp;
            }
            else
            {
                curr->next = temp;
                curr = temp;
            }
        }
        else
        {
            return head;
        }
    }
}

// Driver program to test above functions
int main()
{
	int k = 3; // Number of linked lists
	int n = 4; // Number of elements in each list

	// an array of pointers storing the head nodes
	// of the linked lists
	Node* arr[k];

	arr[0] = new Node(1);
	arr[0]->next = new Node(3);
	arr[0]->next->next = new Node(5);
	arr[0]->next->next->next = new Node(7);

	arr[1] = new Node(2);
	arr[1]->next = new Node(4);
	arr[1]->next->next = new Node(6);
	arr[1]->next->next->next = new Node(8);

	arr[2] = new Node(0);
	arr[2]->next = new Node(9);
	arr[2]->next->next = new Node(10);
	arr[2]->next->next->next = new Node(11);

	// Merge all lists
	Node* head = mergeKLists(arr, k);

	printList(head);

	return 0;
}
