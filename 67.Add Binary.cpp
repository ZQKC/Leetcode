class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() > b.length())
            b = std::string(a.length() - b.length(), '0') + b;
        else
            a = std::string(b.length() - a.length(), '0') + a;
        
        std::string ans;
        int tag = 0;
        for (int i = a.length() - 1; i >= 0; --i) {
            ans = (a[i] - '0' + b[i] - '0' + tag & 1? "1": "0") + ans;
            tag = a[i] - '0' + b[i] - '0' + tag >= 2 ? 1: 0;
        }
        if (tag == 1)
            ans = '1' + ans;
        return ans;
    }
};