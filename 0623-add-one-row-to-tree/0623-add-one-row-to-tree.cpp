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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        insertRow(root, v, d, 1);
        return root;
    }
    
    void insertRow(TreeNode* node, int v, int d, int depth) {
        if (!node) return;
        
        if (depth == d - 1) {
            TreeNode* temp = node->left;
            node->left = new TreeNode(v);
            node->left->left = temp;
            
            temp = node->right;
            node->right = new TreeNode(v);
            node->right->right = temp;
            
            return;
        }
        
        insertRow(node->left, v, d, depth + 1);
        insertRow(node->right, v, d, depth + 1);
    }
};
void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
};