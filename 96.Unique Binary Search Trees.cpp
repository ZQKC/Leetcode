class Solution {
public:
    int numTrees(int n) {
        std::vector<int> ans(2);
        ans[0] = ans[1] = 1;
        for (int i = 2; i <= n; ++i) {
            ans.push_back(0);
            for (int j = 0; j < i; ++j) {
                ans[i] += (ans[j] * ans[i - 1 - j]);
            }
        }
        return ans[n];
    }
};