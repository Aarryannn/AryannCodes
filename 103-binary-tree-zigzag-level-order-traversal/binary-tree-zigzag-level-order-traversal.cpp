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
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        bool ques = true; 
        q.push(root);
        while(q.size()){
            int n = q.size();
            vector<int> temp(n);

            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
    int idx;
                 if(ques) idx = i;
                 else{
                    idx = n-1-i;
                 }
                 temp[idx] =  curr->val;

                 if(curr-> left) q.push(curr->left);
                 if(curr-> right) q.push(curr->right);
            }
            res.push_back(temp);
            ques = !ques;
        }
        return res;




    }
};