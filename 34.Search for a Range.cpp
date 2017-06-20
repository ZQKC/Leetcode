class Solution {
public:
    int bsearch(const std::vector<int> &nums, int beg, int end, int target) {
        while (beg <= end) {
            int mid = (beg + end) / 2;
            if (nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> ans(2);
        ans[0] = ans[1] = bsearch(nums, 0, nums.size() - 1, target);
        if (ans[0] == -1)
            return ans;
        
        while (ans[0]-1 >= 0 && nums[ans[0]-1]==target) {
            --ans[0];
        }
        while (ans[1]+1 < nums.size() && nums[ans[1]+1]==target) {
            ++ans[1];
        }
        return ans;
    }
};