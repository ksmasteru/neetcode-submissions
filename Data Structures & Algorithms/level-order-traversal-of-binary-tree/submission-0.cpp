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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int len = 0;
        queue<TreeNode*> queue;
        TreeNode* current;
        vector<vector<int>> res;
        vector<int> sub;
        if (root)
        {
            queue.push(root);
        }
        while (queue.size() > 0)
        {
            len = queue.size();
            for (int i = 0; i < len; i++)
            {
                current = queue.front();
                queue.pop();
                sub.push_back(current->val);
                if (current->left)
                    queue.push(current->left);
                if (current->right)
                    queue.push(current->right);
            }
            res.push_back(sub);
            sub.clear();
        }
        return (res);
    }
};
