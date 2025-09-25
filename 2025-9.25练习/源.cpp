class Solution {
public:
    int mySqrt(int a) {
        if (a == 0 || a == 1) {
            return a;
        }

        long x = a;
        while (x > a / x) {
            x = (x + a / x) / 2;
        }

        return (int)x;
    }
};