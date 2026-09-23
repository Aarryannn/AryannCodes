class Solution {
public:
    void solve(TreeNode* root, string path, vector<string>& ans) {
        if (!root)
            return;

        path += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        path += "->";

        solve(root->left, path, ans);
        solve(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }
};