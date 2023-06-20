#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
    Node(int value)
    {
        data = value;
        lchild = NULL;
        rchild = NULL;
    }
};

void insert(Node *root, int key)
{
    queue<Node *> q;
    q.push(root);

    // Do level order traversal until we find an empty spot
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->lchild == NULL)
        {
            curr->lchild = new Node(key);
            break;
        }
        else
        {
            q.push(curr->lchild);
        }

        if (curr->rchild == NULL)
        {
            curr->rchild = new Node(key);
            break;
        }
        else
        {
            q.push(curr->rchild);
        }
    }
}

int main()
{
    int n, input;
    cin >> n;
    struct Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (i == 0)
        {
            root = new Node(input);
        }
        else
        {
            insert(root, input);
        }
    }

    return 0;
}