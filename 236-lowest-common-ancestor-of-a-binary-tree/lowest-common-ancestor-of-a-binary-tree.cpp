/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val == p->val || root->val == q->val) 
            return root;

        TreeNode* la = lowestCommonAncestor(root->left, p, q);
        TreeNode* ra = lowestCommonAncestor(root->right, p, q);

        if(la && ra) return root;
        else if(la) return la;
        else return ra;

    }
};