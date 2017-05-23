class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> ans(digits.size());

        int tag = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            ans[i] = (digits[i] + tag) % 10;
            tag = digits[i] + tag >= 10 ? 1: 0;
        }
        if (tag == 1)
            ans.insert(ans.begin(), 1);
        return ans;
    }
};