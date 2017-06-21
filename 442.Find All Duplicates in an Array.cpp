class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) 
                ans.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return ans;
    }
};