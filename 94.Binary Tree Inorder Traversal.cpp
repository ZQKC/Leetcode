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
private:
    void _inorderTraversal(TreeNode* root, std::vector<int> &ans) {
        if (root == NULL) {
            return ;
        }
        _inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        _inorderTraversal(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        _inorderTraversal(root, ans);
        return ans;
    }
};