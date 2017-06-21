class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) 
                continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] > nums[k])
                        ++ans;
                    else
                        break;
                }
            }
        }
        return ans;
    }
};