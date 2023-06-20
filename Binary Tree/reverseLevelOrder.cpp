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
    vector<int> reverseLevelOrder(Node *root)
    {
        stack<Node *> s;
        queue<Node *> q;
        vector<int> output;
        q.push(root);

        while (!q.empty())
        {
            root = q.front();
            q.pop();
            s.push(root);

            if (root->right != NULL)
            {
                q.push(root->right);
            }
            if(root->left!=NULL){
                q.push(root->left);
            }
        }
        while (s.empty() == false)
        {
            root = s.top();
            output.push_back(root->data);
            s.pop();
        }
        return output;
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
    vector<int> ans = sol.reverseLevelOrder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}