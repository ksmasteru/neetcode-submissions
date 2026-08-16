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

    void inorder_traversal(TreeNode* root, vector<int>& arr)
    {
        if (!root)
            return ;
        inorder_traversal(root->left, arr);
        arr.push_back(root->val);
        inorder_traversal(root->right, arr);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        // since  this binary tree we can get its values first.
        vector<int>arr;
        inorder_traversal(root, arr);
        return (arr[k - 1]);
    }
};
