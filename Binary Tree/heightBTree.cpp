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

class Solution
{
public:
    int height(Node *root)
    {
        queue<Node *> q;
        int count = 0;
        if (!root)
        {
            return count;
        }
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            root = q.front();
            q.pop();

            if (root == NULL)
            {
                count++;
            }

            if (root != NULL)
            {
                if (root->right != NULL)
                {
                    q.push(root->right);
                }
                if (root->left != NULL)
                {
                    q.push(root->left);
                }
            }
            else if (!q.empty())
            {
                q.push(NULL);
            }
        }
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