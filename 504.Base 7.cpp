class Solution {
public:
    string convertToBase7(int num) {
        std::string ans;
        int tag = num < 0 ? -1 : 1;
        num *= tag;
        if (num == 0)
            return "0";
        
        while (num != 0) {
            ans = char((num%7 + '0')) + ans;
            num /= 7;
        }
        ans = (tag == -1 ? "-" : "") + ans;
        return ans;
    }
};