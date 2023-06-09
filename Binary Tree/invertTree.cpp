#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
    TreeNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void insert(TreeNode *root, int key)
{
    queue<TreeNode *> q;
    q.push(root);

    // Do level order traversal until we find an empty spot
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (curr->left == NULL)
        {
            curr->left = new TreeNode(key);
            break;
        }
        else
        {
            q.push(curr->left);
        }

        if (curr->right == NULL)
        {
            curr->right = new TreeNode(key);
            break;
        }
        else
        {
            q.push(curr->right);
        }
    }
}

void levelOrder(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(node);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        cout<<(temp->data)<<" ";

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
    TreeNode *invertTree(TreeNode *root)
    {
        if(root == NULL){
            return root;
        }
        
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

int main()
{
    int n, input;
    cin >> n;
    struct TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (i == 0)
        {
            root = new TreeNode(input);
        }
        else
        {
            insert(root, input);
        }
    }

    levelOrder(root);
    cout<<endl;
    Solution sol;
    TreeNode* ans = sol.invertTree(root);
    levelOrder(ans);

    return 0;
}