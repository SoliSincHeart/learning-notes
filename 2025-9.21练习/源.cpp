class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = (int)sqrt(c);
        while (left <= right)
        {
            long ret = left * left + right * right;
            if (ret == c)
                return true;
            else if (ret > c)
            {
                --right;
            }
            else if (ret < c)
            {
                ++left;
            }
        }
        return false;
    }
};