class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = 0;
        char str[10003];
        for (int  i = 0; i < num.length(); ++i) {
            int  j = len - 1;
            while(j >= 0 && str[j] > num[i] && (j - i + k >= 0)) 
                --j;
            len = j + 1;
            if (len < num.length() - k)
                str[len++] = num[i];
        }
        str[len] = '\0';
        std::string ans(str);
        for (int i = 0; i < len; ++i) 
            if (ans[i] != '0')
                return ans.substr(i, ans.length() - i);
        return "0";
    }
};