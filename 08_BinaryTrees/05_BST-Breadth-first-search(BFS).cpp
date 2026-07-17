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

// If you are asked for a standard BFS where you just need to search the whole tree and don't care about the levels, you can actually strip out the inner for loop and the level counter entirely to make it even simpler

void BFS(TreeNode *root)
{
    queue<TreeNode *> Q;
    if (root)
        Q.push(root);

    int level = 0;

    while (!Q.empty())
    {
        cout << "level: " << level << endl;
        int length = Q.size();
        for (int i = 0; i < length; i++)
        {
            TreeNode *curr = Q.front();
            Q.pop();
            cout << curr->val_ << " ";
            if (curr->left)
                Q.push(curr->left);
            if (curr->right)
                Q.push(curr->right);
        }
        level++;
        cout << endl;
    }
}

int main()
{
    TreeNode bt(6);
    insert(&bt, 3);
    insert(&bt, 4);
    insert(&bt, 5);
    insert(&bt, 7);
    insert(&bt, 8);
    insert(&bt, 9);

    BFS(&bt);
}