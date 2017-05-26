class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int beg = 1, end = nums.size() - 1;
        while (1) {
            int mid = (beg + end) / 2, less = 0, more = 0, equal = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] >= mid && nums[i] <= end) 
                    ++more;
                if(nums[i] >= beg && nums[i] <= mid)
                    ++less;
                if(nums[i] == mid)
                    ++equal;
            }
            
            if (equal > 1)
                return mid;
            else if (more > end - mid + 1)
                beg = mid + 1;
            else 
                end = mid - 1;
        }
    }
};