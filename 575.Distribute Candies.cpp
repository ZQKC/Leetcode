class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        bool tag[200002] = {0};
        int kinds = 0;
        for (int i = 0; i < candies.size(); ++i){
            if (tag[candies[i] + 100000] == 0){
                ++kinds;
                tag[candies[i] + 100000] = 1;
            }
        }
        if (kinds >= candies.size() / 2)
            return candies.size() / 2;
        else
            return kinds;
    }
};