class Solution {
public:
    int mySqrt(int x) {
        double beg = 0.0, end = x * 1.0;
        while (1) {
            double mid = (beg + end) / 2;
            if (mid * mid > x)
                end = mid;
            else if(mid * mid == x) {
                end = beg = mid;
                break;
            }
            else
                beg = mid;

            if (int(end) == int(beg))
                break;
        }
        return int(beg);
    }
};