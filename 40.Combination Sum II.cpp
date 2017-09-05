class Solution {
private:
    void dfs(const std::map<int, int> &m, std::map<int, int>::iterator it1, int sum, int target, std::vector<int> &path, std::vector<std::vector<int>> &ans) {
        if (sum == target) {
            ans.push_back(path);
            return ;
        }
        else if (sum > target) {
            return ;
        }
        
        for (auto it2 = it1; it2 != m.end(); ++it2) {
            if (it2->second > 0) {
                --(it2->second);
                path.push_back(it2->first);
                dfs(m, it2, sum + it2->first, target, path, ans);
                path.pop_back();
                ++(it2->second);
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> tmp;
        
        std::map<int, int> m;
        for (int i = 0; i < candidates.size(); ++i) {
            m[candidates[i]] = (m.find(candidates[i]) == m.end() ? 1 : m[candidates[i]] + 1);
        } 
        dfs(m, m.begin(), 0, target, tmp, ans);
        
        return ans;
    }
};