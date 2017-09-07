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
    vector<TreeNode*> _generateTrees(int beg, int end) {
        vector<TreeNode*> ans;
        if (beg > end) {
            ans.push_back(NULL);
            return ans;
        }

        for (int i = beg; i <= end; ++i) {
            vector<TreeNode*> left = _generateTrees(beg, i - 1);
            vector<TreeNode*>  right = _generateTrees(i + 1, end);
            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    TreeNode *tmp = new TreeNode(i);
                    tmp->left = left[j];
                    tmp->right = right[k];
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    } 
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return std::vector<TreeNode*>();
        }
        return _generateTrees(1, n);
    }
};