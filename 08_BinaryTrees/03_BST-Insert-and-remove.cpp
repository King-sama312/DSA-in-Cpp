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

// Insert into the tree
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

// Return the minimum value node of the BST.
TreeNode *minValueNode(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr && curr->left)
    {
        curr = curr->left;
    }
    return curr;
}

// Remove a node and return the root of the tree.
TreeNode *remove(TreeNode *root, int val)
{
    // FIX 1: If the tree is empty or the value isn't found, do nothing.
    if (!root)
    {
        return nullptr;
    }

    // Traverse the tree to find the node
    if (val > root->val_)
    {
        root->right = remove(root->right, val);
    }
    else if (val < root->val_)
    {
        root->left = remove(root->left, val);
    }
    // Node found
    else
    {
        // Case 1 & 2: Node has 0 or 1 child
        if (!root->left)
        {
            TreeNode *temp = root->right;
            delete root; // FIX 2: Free the memory of the removed node
            return temp;
        }
        else if (!root->right)
        {
            TreeNode *temp = root->left;
            delete root; // FIX 2: Free the memory of the removed node
            return temp;
        }
        // Case 3: Node has 2 children
        else
        {
            // Find the minimum node in the right subtree
            TreeNode *minNode = minValueNode(root->right);
            // Replace the current node's value with the min node's value
            root->val_ = minNode->val_;
            // Delete the duplicate min node from the right subtree
            root->right = remove(root->right, minNode->val_);
            // Note: We don't delete 'root' here because we only swapped its value.
            // The actual memory deletion happens in the recursive call above.
        }
    }
    return root;
} 