class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }

        int ans = 1, val = nums[0], ti = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (val == nums[i] && ti >= 2) {
                continue;
            }
            nums[ans++] = nums[i];
            if (val == nums[i] && ti < 2) {
                ++ti;
            }
            else {
                val = nums[i];
                ti = 1;
            }
        }
        return ans;
    }
};