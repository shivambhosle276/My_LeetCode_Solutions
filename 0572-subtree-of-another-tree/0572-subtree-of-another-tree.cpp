class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;

        if (p == NULL || q == NULL)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL)
            return false;

        // Check if subtree starts here
        if (isSameTree(root, subRoot))
            return true;

        // Otherwise search left and right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};