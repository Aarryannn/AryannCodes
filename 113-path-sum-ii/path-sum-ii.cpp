class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(TreeNode* root, int targetSum) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right) {
            if (targetSum == root->val)
                ans.push_back(path);
        }

        solve(root->left, targetSum - root->val);
        solve(root->right, targetSum - root->val);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum);
        return ans;
    }
};