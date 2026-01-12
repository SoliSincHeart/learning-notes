class Solution {
public:
    int bitSquareSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int temp = n % 10;
            sum += temp * temp;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int fast = n;
        int slow = n;
        do
        {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (fast != slow);
        return slow == 1;
    }
};