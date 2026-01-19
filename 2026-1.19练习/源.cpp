class Solution {
public:
    bool hasAlternatingBits(int n) {
        long ans = n ^ (n >> 1);
        return (ans & (ans + 1)) == 0;
    }
};