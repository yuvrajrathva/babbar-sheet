#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void insert(Node *root, int key)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->left == NULL)
        {
            curr->left = new Node(key);
            break;
        }
        else
        {
            q.push(curr->left);
        }
        if (curr->right == NULL)
        {
            curr->right = new Node(key);
            break;
        }
        else
        {
            q.push(curr->right);
        }
    }
}

int heightRecursive(Node *root)
{
    int maximum;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftMax = heightRecursive(root->left);
        int rightMax = heightRecursive(root->right);
        if (leftMax > rightMax)
        {
            maximum = leftMax;
        }
        else
        {
            maximum = rightMax;
        }
    }
    return maximum + 1;
}

class Solution
{
public:
    int height(Node *root)
    {
        int count = heightRecursive(root);
        return count;
    }
};

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

    Solution sol;
    cout << sol.height(root);

    return 0;
}