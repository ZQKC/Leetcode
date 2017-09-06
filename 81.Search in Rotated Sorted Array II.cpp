class Solution {
public:
    bool search(const vector<int>& nums, int target, int beg = -1, int end = -1) {
        if (beg == -1 && end == -1) {
            beg = 0;
            end = nums.size() - 1;
        }
        while (beg <= end) {
            int mid = (beg + end) / 2;
            if (target == nums[mid]) {
                return true;
            }
            return search(nums, target, beg, mid - 1) || search(nums, target, mid + 1, end);
        }
        return false;
    }
};