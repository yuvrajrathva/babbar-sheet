#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int n,r;
    cin >> n>>r;
    int input;
    Node* head = NULL;
    Node* temp = NULL;
    for (int i = 0; i < n; i++)
    {
        cin>>input;
        if(i==0){
            head = new Node(input);
            temp = head;
        }
        else{
            temp->next = new Node(input);
            temp = temp->next;
        }
    }

    temp = head;
    int pair1;
    int pair2;
    while(temp){
        
    }

    print(head);

    return 0;
}