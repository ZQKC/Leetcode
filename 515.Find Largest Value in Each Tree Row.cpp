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
    vector<int> largestValues(TreeNode* root) {
        std::vector<int> ans;
        std::queue<std::pair<TreeNode*, int>> que;
        que.push(std::pair<TreeNode*, int>(root, 1));
        while (!que.empty()) {
            std::pair<TreeNode*, int> val = que.front();
            que.pop();
            if (val.first == NULL)
                continue;
            
            if (val.second > ans.size()) 
                ans.push_back(val.first->val);
            else if(val.first->val > ans[val.second - 1])
                ans[val.second - 1] = val.first->val;
            else
                ;
            que.push(std::pair<TreeNode*, int>(val.first->left, val.second+1));
            que.push(std::pair<TreeNode*, int>(val.first->right, val.second+1));
        }
        return ans;
    }
};