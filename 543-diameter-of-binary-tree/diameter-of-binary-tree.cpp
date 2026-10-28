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
    int d = 0;
    int h ( TreeNode* root){
        if(root == NULL) return 0;

        int lh = h(root->left);
        int rh = h(root->right);

        d = max(lh+rh, d);
        return max(lh, rh)+1; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        h(root);

        return d;
    }
};