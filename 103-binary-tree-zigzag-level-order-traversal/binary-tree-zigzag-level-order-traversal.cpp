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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool check = true; // true == l->r , false = r->l;
        while(q.size()){
            int lvl = q.size();
            vector<int> temp(lvl);
            for(int i = 0; i < lvl; i++){
                TreeNode* node = q.front();
                q.pop();
                int idx;
                if(check == false){
                    idx = lvl - 1 - i;
                }else{
                    idx = i;
                }
                temp[idx] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
            check = !check;

        }
        return ans;
    }
};