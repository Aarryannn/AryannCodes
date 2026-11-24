class Solution {
    void dfs(TreeNode* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);
        dfs(node->left, res);
        dfs(node->right, res);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};