class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            if (level == depth - 1) {
                while (size--) {
                    TreeNode* curr = q.front();
                    q.pop();

                    TreeNode* leftNode = new TreeNode(val);
                    TreeNode* rightNode = new TreeNode(val);

                    leftNode->left = curr->left;
                    rightNode->right = curr->right;

                    curr->left = leftNode;
                    curr->right = rightNode;
                }

                break;
            }

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            level++;
        }

        return root;
    }
};