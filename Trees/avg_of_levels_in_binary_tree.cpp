/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
            if(!root) return {};
            queue<TreeNode*> q;
            q.push(root);

            int avg;
            vector<double> res;

            while(!q.empty()) {
                int levelSize = q.size();
                double levelSum = 0;
                
                for(int i = 0; i < levelSize; ++i) {
                    TreeNode* curr = q.front();
                    levelSum += curr->val;
                    q.pop();
                    
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                  res.push_back(levelSum/levelSize);
            }
            return res;
    }
};