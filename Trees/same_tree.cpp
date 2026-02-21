class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are identical
        if (!p && !q) return true;
        
        // If one is null and the other isn't, or values differ, they aren't identical
        if (!p || !q || p->val != q->val) return false;
        
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};