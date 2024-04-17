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
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";

        string cur_path = "";
        string smallest = "{";

        dfs(root, cur_path, smallest);

        return smallest;
    }

    void dfs(TreeNode* node, string cur_path, string& smallest) {
        if (!node) return;

        cur_path = char(node->val + 'a') + cur_path;

        if (!node->left && !node->right) {
            smallest = min(smallest, cur_path);
            return;
        }

        dfs(node->left, cur_path, smallest);
        dfs(node->right, cur_path, smallest);
    }
};