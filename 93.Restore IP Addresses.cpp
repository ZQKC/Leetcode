class Solution {
private:
    void dfs(const std::string &s, int beg, std::string ip, int num, std::vector<std::string> &ans) {
        if (beg == s.length() && num == 4) {
            ans.push_back(ip);
        }
        if (s.length() - beg > (4 - num) * 3) {
            return ;
        }

        std::string tmp_ip;
        for (int i = 0, val = 0; i < 3; ++i) {
            val *= 10;
            val += (s[beg + i] - '0');
            tmp_ip += s[beg + i];
            if (val > 255 || (val != 0 && tmp_ip[0] == '0') || (val == 0 && tmp_ip.length() > 1)) {
                continue;
            }
            if (num == 0)
                dfs(s, beg + i + 1, tmp_ip, num + 1, ans);
            else
                dfs(s, beg + i + 1, ip + '.' + tmp_ip, num + 1, ans);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        std::vector<std::string> ans;
        dfs(s, 0, "", 0, ans);
        return ans;
    }
};