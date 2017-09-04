class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {	
        std::sort(nums.begin(), nums.end());

		int ans = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1, k = nums.size() - 1; j < k;) {
				int val = nums[i] + nums[j] + nums[k];
				if (val == target) {
					return target;
				}
				else if(val > target) {
					--k;
				}
				else {
					++j;
				}
				ans = abs(val-target) < abs(ans-target) ? val: ans;
			}
		}
        return ans;
    }
};