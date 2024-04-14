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
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    
    int dfs(TreeNode* node, bool is_left) {
        if (!node)
            return 0;
        
        if (!node->left && !node->right && is_left)
            return node->val;
        
        return dfs(node->left, true) + dfs(node->right, false);
    }
};