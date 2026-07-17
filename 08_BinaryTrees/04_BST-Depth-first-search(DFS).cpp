#include<bits/stdc++.h>
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

// center -> left -> right

void DFS_PreOrder(TreeNode *root){
    if(!root) return;
   
    cout<< root-> val_ <<" ";
    DFS_PreOrder(root->left);
    DFS_PreOrder(root->right);
}

// left -> center -> right

void DFS_InOrder(TreeNode *root){
    if(!root) return;
   
    DFS_InOrder(root->left);
    cout<< root-> val_<<" ";
    DFS_InOrder(root->right);
}

// left -> right -> center
void DFS_PostOrder(TreeNode *root){
    if(!root) return;
   
    DFS_PostOrder(root->left);
    DFS_PostOrder(root->right);
    cout<< root-> val_<<" ";
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
    DFS_InOrder(&bt);
}