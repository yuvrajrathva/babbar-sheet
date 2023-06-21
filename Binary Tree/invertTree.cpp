#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    struct TreeNode *lchild;
    int data;
    struct TreeNode *rchild;
    TreeNode(int value)
    {
        data = value;
        lchild = NULL;
        rchild = NULL;
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

        if (curr->lchild == NULL)
        {
            curr->lchild = new TreeNode(key);
            break;
        }
        else
        {
            q.push(curr->lchild);
        }

        if (curr->rchild == NULL)
        {
            curr->rchild = new TreeNode(key);
            break;
        }
        else
        {
            q.push(curr->rchild);
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

        if (temp->lchild != NULL)
        {
            q.push(temp->lchild);
        }
        if (temp->rchild != NULL)
        {
            q.push(temp->rchild);
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
        
        invertTree(root->lchild);
        invertTree(root->rchild);
        TreeNode* temp = root->lchild;
        root->lchild = root->rchild;
        root->rchild = temp;

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