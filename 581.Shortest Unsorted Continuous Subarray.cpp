class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;

        int max = nums[0], min = nums[nums.size() - 1];
        bool tag[10002] = {0};
        for(int i = 1, j = nums.size() - 2; i < nums.size() && j >= 0; ++i, --j) {
            if (nums[i] < max)
                tag[i] = 1;
            else
                max = nums[i];
            
            if (nums[j] > min)
                tag[j] = 1;
            else
                min = nums[j];
        }
        
        int beg = -1, end = -1, i = 0, j = nums.size() - 1;
        while (i <= j && (beg == -1 || end == -1)) {
            if (beg == -1 && tag[i] == 1) 
                beg = i;
            else if(beg == -1 && tag[i] == 0)
                ++i;
    
            if(end == -1 && tag[j] == 1)
                end = j;
            else if (end == -1 && tag[j] == 0)
                --j;
        }

        if (end == beg && end == -1)
            return 0;
        return end - beg + 1;
    }
};