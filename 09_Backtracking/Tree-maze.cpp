// we have to reach till a leaf node, the condition is that there mustn't be any 0 value in the way, so wehn we reach a 0 we have to go back to the parent node   i.e backtrack

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val_;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int value)
    {
        val_ = value;
    }
};

TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);

    if (val > root->val_)
    {
        root->right = insert(root->right, val);
    }
    else if (val < root->val_)
    {
        root->left = insert(root->left, val);
    }
    return root;
}

bool canReachLeaf(TreeNode *root)
{
    if (!root || root->val_ == 0)
        return false;

    // Reached leaf node
    if (!root->left && !root->right)
        return true;

    if (canReachLeaf(root->left))
    {
        return true;
    }
    if (canReachLeaf(root->right))
    {
        return true;
    }

    return false;
}

bool leafPath(TreeNode *root, vector<int> path)
{
    if (!root || root->val_ == 0)
        return false;

    path.push_back(root->val_);

    if (!root->left && !root->right)
        return true;

    if (leafPath(root->left, path))
    {
        return true;
    }
    if (leafPath(root->right, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

int main()
{
    TreeNode bt(6);
    insert(&bt, 3);
    insert(&bt, 0);
    insert(&bt, 5);
    insert(&bt, 7);
    insert(&bt, 8);
    insert(&bt, 9);
}