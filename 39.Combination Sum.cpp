class Solution {
private:
    void dfs(const vector<int> &candidates, int pos, int sum, int target, std::vector<int> &path, std::vector<std::vector<int>> &ans) {
        if (sum == target) {
            ans.push_back(path);
            return ;
        }
        else if (sum > target) {
            return ;
        }
        
        for (int i = pos; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            dfs(candidates, i, sum + candidates[i], target, path, ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> tmp;
        
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target, tmp, ans);
        
        return ans;
    }
};