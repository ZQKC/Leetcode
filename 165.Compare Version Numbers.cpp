class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = -1, j = -1;
        while (i < int(version1.length()) || j < int(version2.length())) {
            int n1 = 0, n2 = 0;
            while (++i, i < version1.length() && version1[i] != '.')
                n1 = n1 * 10 + (version1[i] - '0');
            
            while (++j, j < version2.length() && version2[j] != '.')
                n2 = n2 * 10 + (version2[j] - '0');
            
            if (n1 > n2)
                return 1;
            else if(n1 < n2)
                return -1;
            else
                ;
        }
        return 0;
    }
};