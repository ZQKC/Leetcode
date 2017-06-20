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
    
    int search(const std::vector<int> &nums, int beg, int end, int target) {
        int idx1 = -1, idx2 = -1;
        if (beg > end)
            return -1;

        int mid = (beg + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if(mid == beg) {
            idx1 = search(nums, beg + 1, end, target);
        }
        else if (nums[beg] < nums[mid]) {
            idx1 = bsearch(nums, beg, mid, target);
            idx2 = search(nums, mid + 1, end, target);
        }
        else if(nums[beg] > nums[mid]) {
            idx1 = bsearch(nums, mid, end, target);
            idx2 = search(nums, beg, mid - 1, target);
        }

        if (idx1 != -1)
            return idx1;
        if (idx2 != -1)
            return idx2;
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
};