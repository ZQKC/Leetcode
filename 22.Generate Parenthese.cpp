class Solution {
public:
    void dfs(std::string s, int left, int right, int n, std::vector<std::string> &ans) {
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }
        
        if (s.length() == 0)
            dfs("(", 1, 0, n, ans);
        else if (left == right)
            dfs(s+"(", left+1, right, n, ans);
        else if(left == n)
            dfs(s+")", left, right+1, n, ans);
        else if (left > right && left != n) {
            dfs(s+"(", left+1, right, n, ans);
            dfs(s+")", left, right+1, n, ans);
        }
        else
            ;
    }
    
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        dfs("", 0, 0, n, ans);
        return ans;
    }
};