#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
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

void levelOrder(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << (temp->data) << " ";

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> output;
        if (root == NULL)
        {
            return output;
        }

        queue<pair<Node *, int>> q;
        pair<Node *, int> pr;
        map<int, Node *> mp;
        int hd = 0;
        pr.first = root;
        pr.second = hd;
        q.push(pr);
        mp[hd] = q.front().first;

        while (!q.empty())
        {
            Node *temp = q.front().first;
            hd = q.front().second;
            q.pop();

            if (temp->left != NULL)
            {
                pr.first = temp->left;
                pr.second = hd - 1;
                q.push(pr);
                if (mp.find(hd - 1) == mp.end())
                {

                    mp[hd - 1] = temp->left;
                }
            }
            if (temp->right != NULL)
            {
                pr.first = temp->right;
                pr.second = hd + 1;
                q.push(pr);
                if (mp.find(hd + 1) == mp.end())
                {
                    mp[hd + 1] = temp->right;
                }
            }
        }

        for (auto &e : mp)
        {
            output.push_back(e.second->data);
        }

        return output;
    }
};

int main()
{
    int n;
    cin >> n;
    int input;
    struct Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin>>input;
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
    vector<int> ans = sol.topView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
