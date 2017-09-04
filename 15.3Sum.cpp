class Solution {
public:
    vector<vector<int>> threeSum(std::vector<int> nums) {    	
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
        	m[nums[i]] = m.find(nums[i]) == m.end() ? 1 : m[nums[i]] + 1;
		}
		
		std::vector<std::vector<int>> ans;
		for (auto it1 = m.begin(); it1 != m.end(); ++it1) {
			for (auto it2 = it1; it2 != m.end(); ++it2) {
				int val = 0 - (*it1).first - (*it2).first;
				if (val < (*it2).first) {
					continue;
				}
				else if (m.find(val) != m.end() && val != it1->first) {
					if ((val == it2->first && it2->second >= 2) ||
							(it1->first == it2->first && it2->second >= 2) ||
							(it1->first != it2->first && it2->first != val)){
						ans.push_back({it1->first, it2->first, val});	
					}
				}
			}
		}
		
		if (m.find(0) != m.end() && m[0] >= 3) {
			ans.push_back({0, 0, 0});
		}
        return ans;
    }
};