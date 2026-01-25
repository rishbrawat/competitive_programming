class Solution {
public:
    void traverse(TreeNode* root, vector<int>& result) {
        if (!root) return;

        traverse(root->left, result);  // 1. Go Left
        traverse(root->right, result); // 2. Go Right
        result.push_back(root->val); // 3. Visit Root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};